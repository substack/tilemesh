var glsl = require('glslify')
var dmerge = require('deep-assign')

function draw (mesh,camera,state) {
  return {
    frag: `
      precision mediump float;
      varying vec4 vcolor;
      void main () {
        gl_FragColor = vcolor;
      }
    `,
    uniforms: Object.assign(camera.members('proj'), {
      aspect: function (context) {
        return context.viewportWidth / context.viewportHeight
      }
    }),
    attributes: {
      position: mesh.positions,
      angle: mesh.angles,
      roadtype: mesh.types
    },
    elements: mesh.cells
  }
}

exports.click = function (regl, mesh, camera, state) {
  return regl(dmerge(draw(mesh,camera,state), {
    vert: glsl`
      precision mediump float;
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      #pragma glslify: geom = require('./highway-geom.glsl')
      uniform proj_t proj;
      attribute vec2 position, id;
      attribute float angle, roadtype;
      uniform float aspect;
      varying vec4 vcolor;
      void main () {
        vcolor = vec4(id,0,1);
        vec3 p = geom(proj,position,roadtype,angle,aspect);
        gl_Position = vec4(p,1);
      }
    `,
    attributes: {
      id: mesh.ids
    },
    framebuffer: regl.prop('framebuffer')
  }))
}

exports.draw = function (regl, mesh, camera, state) {
  return regl(dmerge(draw(mesh,camera,state), {
    vert: glsl`
      precision mediump float;
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      #pragma glslify: geom = require('./highway-geom.glsl')
      uniform proj_t proj;
      attribute vec2 position, id;
      attribute float angle, roadtype;
      uniform float aspect;
      uniform vec3 colors[19];
      uniform vec2 selected;
      varying vec4 vcolor;
      void main () {
        if (length(selected) > 0.1 && length(selected-id) < 0.1) {
          vcolor = vec4(1,1,1,1);
        } else {
          vcolor = vec4(colors[int(roadtype)],1);
        }
        gl_Position = vec4(geom(proj,position,roadtype,angle,aspect),1);
      }
    `,
    attributes: {
      id: mesh.ids
    },
    uniforms: {
      selected: function () { return state.selected },
      'colors[0]': [1,0,0],
      'colors[1]': [1,0.8,0],
      'colors[2]': [1,0.6,0],
      'colors[3]': [1,0.4,0.3],
      'colors[4]': [1,0.3,0.5],
      'colors[5]': [0.5,0.5,0.5],
      'colors[6]': [0.5,0.5,0.5],
      'colors[7]': [0.5,0.5,0.5],
      'colors[8]': [0.5,0.5,0.5],
      'colors[9]': [0.5,0.5,0.5],
      'colors[10]': [0.5,0.5,0.5],
      'colors[11]': [0.5,0.5,0.5],
      'colors[12]': [0.5,0.5,0.5],
      'colors[13]': [0.5,0.5,0.5],
      'colors[14]': [0.5,0.5,0.5],
      'colors[15]': [0.5,0.5,0.5],
      'colors[16]': [0.5,0.5,0.5],
      'colors[17]': [0.5,0.5,0.5],
      'colors[18]': [0.5,0.5,0.5]
    }
  }))
}
