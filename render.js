var regl = require('regl')({
  extensions: ['OES_element_index_uint','OES_texture_float']
})
var resl = require('resl')
var glsl = require('glslify')
var proj = require('glsl-proj4')
var mat4 = require('gl-mat4')
var nextTick = require('next-tick')

var highway = require('./lib/highway.js')
var boundary = require('./lib/boundary.js')
var natural = require('./lib/natural.js')
var pick = require('./lib/pick.js')(regl)

var camera = require('glsl-proj4-camera')(location.hash.replace(/^#/,'') || `
  +proj=tmerc +lat_0=18.83333333333333 +lon_0=-155.5 +ellps=GRS80 +units=m%0A%0A
  +k_0=0.00010994235090283668 +x_0=-5.638931906678166 +y_0=-8.829793624010414
`.trim())

camera.on('update', function () {
  location.hash = camera.string()
})

resl({
  manifest: {
    /*
    land: {
      type: 'text',
      src: 'hawaii.json',
      parser: JSON.parse
    },
    */
    data: {
      type: 'text',
      src: '6.json',
      parser: JSON.parse
    }
  },
  onDone: ready
})

function ready (assets) {
  var state = { selected: [0,0], hover: [0,0] }
  var draw = {
    highway: highway.draw(regl, {
      labels: assets.data.labels,
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
          return
        }
        state.selected[0] = 0
        state.selected[1] = 0
      }
      frame()
    })
  })
  window.addEventListener('mousemove', function (ev) {
    nextTick(function () {
      for (var key in click) {
        var p = pick(click[key],ev)
        if (p && p[0]+p[1] > 0) {
          state.hover[0] = p[0]
          state.hover[1] = p[1]
          return frame()
        }
      }
      state.hover[0] = 0
      state.hover[1] = 0
      frame()
    })
  })
  window.addEventListener('resize', function () { nextTick(frame) })
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
