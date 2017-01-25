var parser = require('osm-pbf-parser')
var defined = require('defined')
var through = require('through2')
var docs = {}
var mesh = {
  highway: { positions: [], cells: [], angles: [], types: [], ids: [] },
  boundary: { positions: [], cells: [], angles: [], types: [], ids: [] }
}

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

process.stdin.pipe(parser())
  .pipe(through.obj(write, end))

function write (items, enc, next) {
  for (var i = 0; i < items.length; i++) {
    var item = items[i]
    docs[item.id] = item
    if (item.refs && item.tags.boundary) {
      for (var j = 0; j < item.refs.length; j++) {
        addLine(mesh.boundary,item)
        for (var j = 0; j < item.refs.length; j++) {
          mesh.boundary.types.push(0,0)
        }
      }
    } else if (item.refs && item.tags.highway) {
      addLine(mesh.highway,item)
      var roadtype = defined(
        highway[item.tags.highway],
        highway[item.tags.highway+'_link'],
        highway.road)
      for (var j = 0; j < item.refs.length; j++) {
        mesh.highway.types.push(roadtype,roadtype)
      }
    }
  }
  next()
}
function end () {
  console.log(JSON.stringify(mesh))
}

function angle (x) {
  return (x + Math.PI*4)%(2*Math.PI)
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
