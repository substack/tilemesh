#!/usr/bin/env node
var csv = require('csv-parser')
var through = require('through2')

process.stdin.pipe(csv())
  .pipe(enumc())
  .pipe(process.stdout)

function enumc () {
  var n = 0, cat = null
  var stream = through.obj(write, end)
  stream.push('const enum features {')
  return stream
  function write (row, enc, next) {
    if (cat && cat !== row.category) {
      this.push(',\n' + uc(cat) + '_OTHER = ' + (n++))
    }
    cat = row.category
    var k = uc(row.category + '_' + row.type)
    var v = String(n++)
    next(null, (n > 1 ? ',\n' : '\n') + k + '=' + v)
  }
  function end (next) {
    this.push(',\n' + uc(cat) + '_OTHER = ' + (n++)
      + '\n};\n#pragma glslify: export(features)\n')
    next()
  }
}

function uc (s) { return s.toUpperCase() }
