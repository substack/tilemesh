var roads = require('./lib/roads.js')

module.exports = function (regl, camera, data) {
  var state = { selected: [0,0], hover: [0,0] }
  var draw = {
    roads: roads.draw(regl, {
      labels: data.labels,
      characters: data.characters,
      mesh: data.roads,
      camera: camera,
      state: state
    }),
    //boundary: boundary.draw(regl, data.boundary, camera, state),
    //natural: natural.draw(regl, data.natural, camera, state),
    //land: land(regl, land),
  }
  var click = {
    roads: roads.click(regl, {
      mesh: data.roads,
      camera: camera,
      state: state
    }),
    //boundary: boundary.click(regl, data.boundary, camera, state),
    //natural: natural.click(regl, data.natural, camera, state),
  }
  /*
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
  */
  return function (props) {
    draw.roads(props)
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
