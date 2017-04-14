#!/usr/bin/env node
var csv = require('csv-parser')
var through = require('through2')

process.stdin.pipe(csv())
  .pipe(enumc())
  .pipe(process.stdout)

function enumc () {
  var n = 0, cat = null
  var stream = through.obj(write, end)
  stream.push(`
    #ifndef TILEMESH_FEATURES_H
    #define TILEMESH_FEATURES_H
    #include <map>
    #include <stdint.h>
    
    typedef std::map<const char *,size_t> Features;
    void load_features (Features *features) {
  `.replace(/^ {4}/mg,'').trim()+'\n')
  return stream
  function write (row, enc, next) {
    if (cat && cat !== row.category) {
      var catstr = '"' + cat+'\\0"'
      this.push(`  (*features)[${catstr}] = ${n++};\n`)
    }
    cat = row.category
    var k = row.category + '.' + row.type
    var kstr = '"'+k+'\\0"'
    var v = String(n++)
    next(null, `  (*features)[${kstr}] = ${v};\n`)
  }
  function end (next) {
    var catstr = '"' + cat+'\\0"'
    this.push(`
        (*features)[${catstr}] = ${n++};
      };
      #endif
    `.replace(/^ {6}/mg,'').replace(/^\s*\n/,'') + '\n')
    next()
  }
}

function uc (s) { return s.toUpperCase() }
