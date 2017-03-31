#!/usr/bin/env node
var csv = require('csv-parser')
var through = require('through2')

process.stdin.pipe(csv())
  .pipe(enumjson())
  .pipe(process.stdout)

function enumjson () {
  var n = 0, cat = null
  var stream = through.obj(write, end)
  stream.push('{')
  return stream
  function write (row, enc, next) {
    if (cat && cat !== row.category) {
      this.push(',\n' + JSON.stringify(cat + '.other') + ':' + (n++))
    }
    cat = row.category
    var k = JSON.stringify(row.category + '.' + row.type)
    var v = JSON.stringify(n++)
    next(null, (n > 1 ? ',\n' : '') + k + ':' + v)
  }
  function end (next) {
    this.push(',\n' + JSON.stringify(cat + '.other') + ':' + (n++) + '}\n')
    next()
  }
}
