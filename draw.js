var roads = require('./lib/roads.js')

module.exports = function (regl, opts) {
  var state = { selected: [0,0], hover: [0,0] }
  return function (data) {
    var draw = {
      roads: roads.draw(regl, {
        labels: data.labels,
        characters: data.characters,
        mesh: data.roads,
        uniforms: opts.uniforms,
        state: state
      }),
      //boundary: boundary.draw(regl, data.boundary, state),
      //natural: natural.draw(regl, data.natural, state),
    }
    var click = {
      roads: roads.click(regl, {
        mesh: data.roads,
        uniforms: opts.uniforms,
        state: state
      }),
      //boundary: boundary.click(regl, data.boundary, state),
      //natural: natural.click(regl, data.natural, state),
    }
    return function (props) {
      draw.roads(props)
    }
  }
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
