var glsl = require('glslify')
var dmerge = require('deep-assign')

function draw (mesh,camera,state) {
  return {
    frag: `
      precision highp float;
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
      type: mesh.types
    },
    elements: mesh.cells
  }
}

exports.click = function (regl, mesh, camera, state) {
  return regl(dmerge(draw(mesh,camera,state), {
    vert: glsl`
      precision highp float;
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      #pragma glslify: geom = require('./boundary-geom.glsl')
      uniform proj_t proj;
      attribute vec2 position, id;
      attribute float angle;
      uniform float aspect;
      varying vec4 vcolor;
      void main () {
        vcolor = vec4(id,0,1);
        vec3 p = geom(proj,position,angle,aspect);
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
      precision highp float;
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      #pragma glslify: geom = require('./boundary-geom.glsl')
      uniform proj_t proj;
      attribute vec2 position, id;
      attribute float angle;
      uniform float aspect;
      uniform vec3 colors[1];
      uniform vec2 selected, hover;
      varying vec4 vcolor;
      void main () {
        if (length(selected) > 0.1 && length(selected-id) < 0.1) {
          vcolor = vec4(1,1,1,1);
        } else if (length(hover) > 0.1 && length(hover-id) < 0.1) {
          vcolor = vec4(pow(colors[0]*0.5+vec3(0,0.8,0),vec3(2.2)),1);
        } else {
          vcolor = vec4(pow(colors[0],vec3(2.2)),1);
        }
        gl_Position = vec4(geom(proj,position,angle,aspect),1);
      }
    `,
    attributes: {
      id: mesh.ids
    },
    uniforms: {
      selected: function () { return state.selected },
      hover: function () { return state.hover },
      'colors[0]': [0.4,0.5,0.6],
    }
  }))
}
