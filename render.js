var regl = require('regl')()
var resl = require('resl')
var glsl = require('glslify')
var proj = require('glsl-proj4')
var mat4 = require('gl-mat4')
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
    lines: {
      type: 'text',
      src: '6.json',
      parser: JSON.parse
    }
  },
  onDone: ready
})

function ready (assets) {
  var draw = {
    lines: lines(regl, assets.lines),
    land: land(regl, assets.land)
  }
  regl.frame(function () {
    regl.clear({ color: [0,0,0,1], depth: true })
    draw.land()
    draw.lines()
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
function lines (regl, mesh) {
  return regl({
    frag: `
      precision mediump float;
      void main () {
        gl_FragColor = vec4(1,0.5,0.5,1);
      }
    `,
    vert: glsl`
      precision mediump float;
      #pragma glslify: forward = require('glsl-proj4/tmerc/forward')
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      uniform proj_t proj;
      attribute vec2 position;
      attribute float angle;
      uniform float aspect;
      void main () {
        vec3 p = forward(proj,position)*vec3(1,aspect,1);
        vec2 adir = vec2(cos(angle),sin(angle))*0.001;
        vec3 np = forward(proj,position+adir)*vec3(1,aspect,1);
        vec3 dir = normalize(np-p);
        gl_Position = vec4(p+dir*0.002,1);
        //gl_Position = vec4(p,1);
      }
    `,
    uniforms: Object.assign(camera.members('proj'), {
      aspect: function (context) {
        return context.viewportWidth / context.viewportHeight
      }
    }),
    attributes: {
      position: mesh.positions,
      angle: mesh.angles
    },
    elements: mesh.cells,
    blend: {
      enable: true,
      func: { src: 'src alpha', dst: 'one minus src alpha' }
    }
  })
}
