var xhr = require('xhr')
var once = require('once')
var overlap = require('./lib/overlap.js')
var hash = 'QmNPkqYfis1XV2CcAyE9ByttxGnvvtVJ4VfFXtbBWnd7fW'
var href = 'http://localhost:8080/ipfs/'+hash+'/'

module.exports = function (viewbox,cb) {
  files(href,viewbox,cb)
}

function files (href,viewbox,cb) {
  cb = once(cb)
  var results = []
  xhr(href+'/meta.json', function (err,res,body) {
    if (err) cb(null, href)
    var meta = JSON.parse(body)
    var pending = 1
    Object.keys(meta).forEach(function (key) {
      var box = meta[key]
      if (overlap(viewbox)) {
        pending++
        files(href+'/'+key,viewbox,finish)
      }
    })
    finish()
    function finish (err,file) {
      if (err) return cb(err)
      results.push(file)
      if (--pending === 0) done()
    }
  })
  function done () { if (cb) cb(null,results) }
}
