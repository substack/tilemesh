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
listFiles(viewbox(projstr), onlist)

camera.on('update', function () {
  var pstr = camera.string()
  location.hash = pstr
  var box = viewbox(pstr)
  frame()
  listFiles(box, onlist)
})
window.addEventListener('resize', frame)

function frame () {
  regl.poll()
  regl.clear({ color: [0.2,0.2,0.2,1], depth: true })
  for (var i = 0; i < draws.length; i++) draws[i].draw()
}

function onlist (err, files) {
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

/*
function ready (assets) {
  var state = { selected: [0,0], hover: [0,0] }
  var draw = {
    highway: highway.draw(regl, {
      labels: assets.data.labels,
      characters: assets.data.characters,
      mesh: assets.data.highway,
      camera: camera,
      state: state
    }),
    //boundary: boundary.draw(regl, assets.data.boundary, camera, state),
    //natural: natural.draw(regl, assets.data.natural, camera, state),
    //land: land(regl, assets.land),
  }
  var click = {
    highway: highway.click(regl, {
      mesh: assets.data.highway,
      camera: camera,
      state: state
    }),
    //boundary: boundary.click(regl, assets.data.boundary, camera, state),
    //natural: natural.click(regl, assets.data.natural, camera, state),
  }
  frame()
  camera.on('update', frame)
  function frame () {
    regl.poll()
    regl.clear({ color: [0.2,0.2,0.2,1], depth: true })
    //draw.land()
    draw.highway()
    //draw.boundary()
    //draw.natural()
  }
  window.addEventListener('click', function (ev) {
    nextTick(function () {
      for (var key in click) {
        var p = pick(click[key],ev)
        if (p && p[0]+p[1] > 0) {
          state.selected[0] = p[0]
          state.selected[1] = p[1]
          return frame()
        }
        state.selected[0] = 0
        state.selected[1] = 0
      }
      frame()
    })
  })
  window.addEventListener('mousemove', function (ev) {
    var prev
    nextTick(function () {
      prev = state.hover.slice()
      for (var key in click) {
        var p = pick(click[key],ev)
        if (p && p[0]+p[1] > 0) {
          state.hover[0] = p[0]
          state.hover[1] = p[1]
          return check()
        }
      }
      state.hover[0] = 0
      state.hover[1] = 0
      check()
    })
    function check () {
      if (state.hover[0] !== prev[0] || state.hover[1] !== prev[1]) {
        frame()
      }
    }
  })
  window.addEventListener('resize', frame)
}

function land (regl, mesh) {
  return regl({
    frag: `
      precision mediump float;
      void main () {
        gl_FragColor = vec4(0.1,0.1,0.1,1);
      }
    `,
    vert: glsl`
      precision mediump float;
      #pragma glslify: forward = require('glsl-proj4/tmerc/forward')
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      uniform proj_t proj;
      attribute vec2 position;
      uniform float aspect;
      void main () {
        vec3 p = forward(proj,position)*vec3(1,aspect,1);
        gl_Position = vec4(p,1);
      }
    `,
    uniforms: Object.assign(camera.members('proj'), {
      aspect: function (context) {
        return context.viewportWidth / context.viewportHeight
      }
    }),
    attributes: {
      position: mesh.positions
    },
    elements: mesh.cells,
    depth: { enable: false, mask: false }
  })
}
*/
