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
  var state = { selected: [0,0] }
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
  var radius = 15
  var data = new Float32Array(radius*radius*4)
  window.addEventListener('click', function (ev) {
    regl.clear({ color: [0,0,0,1], depth: true })
    var mx = ev.offsetX
    var my = window.innerHeight-ev.offsetY
    if (mx < 0 || mx >= window.innerWidth) return
    if (my < 0 || my >= window.innerHeight) return
    fb.resize(window.innerWidth, window.innerHeight)
    draw.highwayClick({ framebuffer: fb }, function () {
      regl.draw()
      var data = regl.read({
        x: Math.floor(mx-radius*0.5),
        y: Math.floor(my-radius*0.5),
        width: Math.min(window.innerWidth-mx,radius),
        height: Math.min(window.innerHeight-my,radius),
        data: data
      })
      var samples = {}, maxkey = null, maxv = [0,0]
      for (var y = 0; y < radius; y++) {
        for (var x = 0; x < radius; x++) {
          var d0 = data[x*4+y*4*radius+0]
          var d1 = data[x*4+y*4*radius+1]
          if (d0+d1>0) {
            var key = d0+','+d1
            var xr = (x-radius*0.5)/radius*2
            var yr = (y-radius*0.5)/radius*2
            samples[key] = (samples[key] || 0)
              + (1-Math.sqrt(xr*xr+yr*yr))
            if (!maxkey || samples[key] > samples[maxkey]) {
              maxkey = key
              maxv = [d0,d1]
            }
          }
        }
      }
      state.selected[0] = maxv[0]
      state.selected[1] = maxv[1]
    })
  })
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
