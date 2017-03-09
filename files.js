var xhr = require('xhr')
var once = require('once')
var overlap = require('./lib/overlap.js')
var hash = 'QmNPkqYfis1XV2CcAyE9ByttxGnvvtVJ4VfFXtbBWnd7fW'
var href = 'http://localhost:8080/ipfs/'+hash
var cache = {}

module.exports = function (viewbox,cb) {
  files(href,viewbox,cb)
}

function files (href,viewbox,cb) {
  cb = once(cb)
  var results = []
  if (cache[href]) process(cache[href])
  else if (cache[href] === null) {
    cb(null, [href + '.o5m.gz'])
  } else xhr(href+'/meta.json', function (err,res,body) {
    if (err || res.statusCode === 404) {
      cache[href] = null
      cb(null, [href + '.o5m.gz'])
    } else process(JSON.parse(body))
  })
  function process (meta) {
    cache[href] = meta
    var pending = 1
    Object.keys(meta).forEach(function (key) {
      var box = meta[key]
      if (overlap(box,viewbox)) {
        pending++
        files(href+'/'+key,viewbox,finish)
      }
    })
    finish()
    function finish (err,files) {
      if (err) return cb(err)
      results = results.concat(files).filter(Boolean)
      if (--pending === 0) done()
    }
  }
  function done () { if (cb) cb(null,results) }
}
