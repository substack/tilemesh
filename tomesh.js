var parser = require('osm-pbf-parser')
var through = require('through2')
var docs = {}, mesh = { positions: [], cells: [] }

process.stdin.pipe(parser())
  .pipe(through.obj(write, end))
function write (items, enc, next) {
  for (var i = 0; i < items.length; i++) {
    var item = items[i]
    docs[item.id] = item
    if (item.refs && item.tags.highway) {
      var poly = []
      var n = mesh.positions.length
      for (var j = 0; j < item.refs.length-1; j++) {
        mesh.cells.push([n+j,n+j+1])
      }
      for (var j = 0; j < item.refs.length; j++) {
        var ref = item.refs[j]
        var pt = [docs[ref].lon,docs[ref].lat]
        mesh.positions.push(pt)
      }
    }
  }
  next()
}
function end () {
  console.log(JSON.stringify(mesh))
}
