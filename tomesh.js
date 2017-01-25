var parser = require('osm-pbf-parser')
var defined = require('defined')
var through = require('through2')
var docs = {}
var mesh = { positions: [], cells: [], angles: [] }

process.stdin.pipe(parser())
  .pipe(through.obj(write, end))

function write (items, enc, next) {
  for (var i = 0; i < items.length; i++) {
    var item = items[i]
    docs[item.id] = item
    if (item.refs && item.tags.highway) {
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
