var parser = require('osm-pbf-parser')
var defined = require('defined')
var through = require('through2')
var vtatlas = require('vector-text-atlas')
var vtext = require('vectorize-text')
var cdt = require('cdt2d')
var dup = require('duplexify')
var pump = require('pump')

var highway = {
  motorway: 1,
  trunk: 2,
  primary: 3,
  secondary: 4,
  tertiary: 5,
  unclassified: 6,
  residential: 7,
  service: 8,
  living_street: 9,
  pedestrian: 10,
  track: 11,
  bus_guideway: 12,
  escape: 13,
  raceway: 14,
  road: 15,
  footway: 16,
  bridleway: 17,
  steps: 18,
  path: 19
}

module.exports = function (opts, cb) {
  var docs = {}
  var mesh = {
    roads: { positions: [], cells: [], angles: [], types: [], ids: [] },
    //boundary: { positions: [], cells: [], angles: [], types: [], ids: [] },
    //natural: { positions: [], cells: [], angles: [], types: [], ids: [] },
    labels: {},
    characters: {}
  }
  var vt = vtatlas({
    canvas: opts.canvas,
    vtext: vtext,
    cdt: cdt
  })
  var d = dup()
  var p = parser()
  d.setWritable(p)
  pump(p, through.obj(write,end))
  return d

  function write (items, enc, next) {
    for (var i = 0; i < items.length; i++) {
      var item = items[i]
      docs[item.id] = item
      if (item.refs && item.tags.boundary) {
        // ...
      } else if (item.refs && item.tags.natural) {
        // ...
      } else if (item.refs && item.tags.highway) {
        addLine(mesh.roads,item)
        var roadtype = defined(
          highway[item.tags.highway],
          highway[item.tags.highway+'_link'],
          highway.road)
        for (var j = 0; j < item.refs.length; j++) {
          mesh.roads.types.push(roadtype,roadtype)
        }
        if (item.tags.name) {
          var a = docs[item.refs[Math.floor(item.refs.length/2)]]
          var b = docs[item.refs[Math.floor(item.refs.length/2)+1]]
          if (!a || !b) continue
          var theta = Math.atan2(a.lat-b.lat,a.lon-b.lon)
          mesh.labels[item.id] = [
            item.tags.name,
            (a.lon+b.lon)*0.5,
            (a.lat+b.lat)*0.5,
            theta
          ]
          vt.add(item.tags.name)
        }
      }
    }
    next()
  }
  function end () {
    mesh.characters = vt.data('array')
    if (cb) cb(null, mesh)
  }
  function addLine (mesh, item) {
    for (var j = 0; j < item.refs.length; j++) {
      var ref = item.refs[j]
      var pt = [docs[ref].lon,docs[ref].lat]
      mesh.positions.push(pt,pt)
      var n = mesh.positions.length
      if (j > 0) {
        mesh.cells.push([n-1,n-2,n-3])
        mesh.cells.push([n-2,n-4,n-3])
      }
      var pref = defined(item.refs[j-1],ref)
      var ppt = [docs[pref].lon,docs[pref].lat]
      var nref = defined(item.refs[j+1],ref)
      var npt = [docs[nref].lon,docs[nref].lat]
      var theta = Math.atan2(npt[1]-ppt[1],npt[0]-ppt[0])
      mesh.angles.push(angle(theta+Math.PI/2))
      mesh.angles.push(angle(theta-Math.PI/2))
      var id = [
        Math.floor(item.id/Math.pow(2,23)),
        item.id%Math.pow(2,23)
      ]
      mesh.ids.push(id,id)
    }
  }
}

function angle (x) {
  return (x + Math.PI*4)%(2*Math.PI)
}
