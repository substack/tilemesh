var regl = require('regl')({
  extensions: ['OES_element_index_uint','OES_texture_float']
})
var resl = require('resl')
var glsl = require('glslify')
var proj = require('glsl-proj4')
var mat4 = require('gl-mat4')

var highway = require('./lib/highway.js')

var camera = require('glsl-proj4-camera')(location.hash.replace(/^#/,'') || `
  +proj=tmerc +lat_0=18.83333333333333 +lon_0=-155.5 +ellps=GRS80 +units=m
  +k_0=0.0000019268500651226404 +x_0=0.35589838 +y_0=-0.34185734
`.trim())

camera.on('update', function () {
  location.hash = camera.string()
})

resl({
  manifest: {
    land: {
      type: 'text',
      src: 'hawaii.json',
      parser: JSON.parse
    },
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
    highway: highway.draw(regl, assets.data.highway, camera, state),
    highwayClick: highway.click(regl, assets.data.highway, camera, state),
    land: land(regl, assets.land)
  }
  regl.frame(function () {
    regl.clear({ color: [0,0,0,1], depth: true })
    draw.land()
    draw.highway()
  })
  var fb = regl.framebuffer({
    colorFormat: 'rgba',
    colorType: 'float32'
  })
  var radius = 10
  var data = new Float32Array(radius*radius*4*4)
  window.addEventListener('click', function (ev) {
    var p = pick(ev)
    state.selected[0] = p[0]
    state.selected[1] = p[1]
  })
  window.addEventListener('mousemove', function (ev) {
    var p = pick(ev)
    if (p) {
      state.hover[0] = p[0]
      state.hover[1] = p[1]
    }
  })
  function pick (ev) {
    var mx = ev.offsetX
    var my = window.innerHeight-ev.offsetY
    if (mx < 0 || mx >= window.innerWidth) return
    if (my < 0 || my >= window.innerHeight) return
    fb.resize(window.innerWidth, window.innerHeight)
    regl.clear({ color: [0,0,0,1], depth: true, framebuffer: fb })
    var res = null
    draw.highwayClick({ framebuffer: fb }, function () {
      regl.draw()
      var rprops = {
        x: Math.max(0,mx-Math.min(window.innerWidth-mx,radius)),
        y: Math.max(0,my-Math.min(window.innerHeight-my,radius)),
        width: Math.min(window.innerWidth-mx,radius*2),
        height: Math.min(window.innerHeight-my,radius*2),
        data: data
      }
      var data = regl.read(rprops)
      var samples = {}, maxkey = null, maxv = [0,0]
      for (var y = 0; y < radius*2; y++) {
        for (var x = 0; x < radius*2; x++) {
          var d0 = data[x*4+y*4*radius*2+0]
          var d1 = data[x*4+y*4*radius*2+1]
          if (d0+d1>0) {
            var key = d0+','+d1
            var xr = (x-radius)/radius
            var yr = (y-radius)/radius
            samples[key] = (samples[key] || 0)
              + (1-Math.sqrt(xr*xr+yr*yr))
            if (!maxkey || samples[key] > samples[maxkey]) {
              maxkey = key
              maxv = [d0,d1]
            }
          }
        }
      }
      res = maxv
    })
    return res
  }
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
