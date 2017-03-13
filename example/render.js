var regl = require('regl')({
  extensions: ['OES_element_index_uint','OES_texture_float']
})
var resl = require('resl')
var glsl = require('glslify')
var proj = require('glsl-proj4')
var mat4 = require('gl-mat4')
var nextTick = require('next-tick')
var overlap = require('../lib/overlap.js')
var xhr = require('xhr')

var proj = require('proj4')
var projstr = location.hash.replace(/^#/,'') || `
  +proj=tmerc +lat_0=18.83333333333333 +lon_0=-155.5 +ellps=GRS80 +units=m
  +k_0=0.00010994235090283668 +x_0=-5.638931906678166 +y_0=-8.829793624010414
`.trim()
var camera = require('glsl-proj4-camera')(projstr)
var draws = []
var tilemesh = require('../draw.js')

var listFiles = require('../files.js')
listFiles(viewbox(projstr), function (err, files) {
  onlist(err, files, frame)
})

camera.on('update', function () {
  var pstr = camera.string()
  location.hash = pstr
  var box = viewbox(pstr)
  frame()
  listFiles(box, onlist)
})
window.addEventListener('resize', frame)
var opts = { labels: false }

function frame () {
  regl.poll()
  regl.clear({ color: [0.2,0.2,0.2,1], depth: true })
  for (var i = 0; i < draws.length; i++) draws[i].draw(opts)
}

function onlist (err, files, cb) {
  var newdraws = []
  var pending = files.length
  files.forEach(function (file) {
    file = '/data/'+(new URL(file)).pathname.split('/').slice(3).join('/')
    var jfile = file.replace(/\.o5m\.gz$/,'.json')
    for (var i = 0; i < draws.length; i++) {
      if (draws[i].file === jfile) {
        newdraws.push(draws[i])
        if (--pending === 0) done()
        return
      }
    }
    xhr(jfile, function (err, res, body) {
      var data = JSON.parse(body)
      newdraws.push({ file: jfile, draw: tilemesh(regl, camera, data) })
      if (--pending === 0) done()
    })
  })
  function done () {
    draws = newdraws
    if (cb) cb()
  }
}

function viewbox (projstr) {
  var sw = proj(projstr,'+proj=longlat +datum=WGS84',[-1,-1])
  var se = proj(projstr,'+proj=longlat +datum=WGS84',[+1,-1])
  var nw = proj(projstr,'+proj=longlat +datum=WGS84',[-1,+1])
  var ne = proj(projstr,'+proj=longlat +datum=WGS84',[+1,+1])
  var w = Math.min(sw[0],nw[0])
  var s = Math.min(sw[1],se[1])
  var e = Math.max(sw[0],nw[0])
  var n = Math.max(nw[1],ne[1])
  return [w,s,e,n]
}
