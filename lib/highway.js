var glsl = require('glslify')
var dmerge = require('deep-assign')

function draw (mesh,camera) {
  return {
    vert: glsl`
      precision mediump float;
      #pragma glslify: forward = require('glsl-proj4/tmerc/forward')
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      uniform proj_t proj;
      attribute vec2 position;
      attribute float angle, roadtype;
      attribute float id;
      uniform float aspect;
      uniform vec3 colors[19];
      varying vec3 vcolor;
      varying float vid;
      void main () {
        vid = id;
        vcolor = colors[int(roadtype)];
        vec3 p = forward(proj,position)*vec3(1,aspect,1);
        vec2 adir = vec2(cos(angle),sin(angle))*0.001;
        vec3 np = forward(proj,position+adir)*vec3(1,aspect,1);
        vec3 dir = normalize(np-p);
        gl_Position = vec4((p+dir
          * max(0.005*pow(1.0/roadtype,1.2),proj.k0*(40.0-roadtype*2.0))
            * step(1e-6,proj.k0/roadtype)).xy,
          1.0-1.0/roadtype, 1);
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
      roadtype: mesh.types,
      id: mesh.ids
    },
    elements: mesh.cells
  }
}

exports.draw = function (regl, mesh, camera) {
  return regl(dmerge(draw(mesh,camera), {
    frag: `
      precision mediump float;
      varying vec3 vcolor;
      void main () {
        gl_FragColor = vec4(vcolor,1);
      }
    `,
    uniforms: {
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
