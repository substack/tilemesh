var parser = require('osm-pbf-parser')
var defined = require('defined')
var through = require('through2')
var vtatlas = require('vector-text-atlas')
var vtext = require('vectorize-text')
var cdt = require('cdt2d')
var dup = require('duplexify')
var pump = require('pump')
var isArea = require('id-area-keys').isArea

var highway = require('./types/highway.json')

module.exports = function (opts, cb) {
  var docs = {}
  var data = {
    points: {
      positions: [],
      id: [],
      type: []
    },
    lines: {
      positions: [],
      id: [],
      index: [],
      distance: [],
      type: [],
      normal: []
    },
    areas: {
      positions: [],
      cells: [],
      id: [],
      index: [],
      type: []
    },
    outlines: {
      positions: [],
      id: [],
      index: [],
      distance: [],
      type: [],
      normal: []
    },
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
      if (item.refs && isArea(item)) {
        addArea(data,docs,item)
      } else if (item.refs) {
        addLine(data,docs,item)
      } else if (item.type === 'node') {
        addPoint(data,docs,item)
      }
      if (item.tags.name) {
        var a = docs[item.refs[Math.floor(item.refs.length/2)]]
        var b = docs[item.refs[Math.floor(item.refs.length/2)+1]]
        if (!a || !b) continue
        var theta = Math.atan2(a.lat-b.lat,a.lon-b.lon)
        data.labels[item.id] = [
          item.tags.name,
          (a.lon+b.lon)*0.5,
          (a.lat+b.lat)*0.5,
          theta
        ]
        vt.add(item.tags.name)
      }
    }
    next()
  }
  function end () {
    data.characters = vt.data('array')
    if (cb) cb(null, data)
  }
}

var pt0 = [0,0], pt1 = [0,0]
function addLine (data, docs, item) {
  for (var j = 0; j < item.refs.length; j++) {
    var ref = item.refs[j]
    var nref = defined(item.refs[j+1],ref)
    pt0[0] = docs[ref].lon
    pt0[1] = docs[ref].lat
    pt1[0] = docs[nref].lon
    pt1[1] = docs[nref].lat
    mesh.positions.push(pt0,pt1,pt0,pt1)
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
function angle (x) {
  return (x + Math.PI*4)%(2*Math.PI)
}
