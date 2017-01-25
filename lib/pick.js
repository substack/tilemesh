module.exports = function (regl) {
  var radius = 10
  var data = new Float32Array(radius*radius*4*4)
  var fb = regl.framebuffer({
    colorFormat: 'rgba',
    colorType: 'float32'
  })
  return function (draw, ev) {
    var mx = ev.offsetX
    var my = window.innerHeight-ev.offsetY
    if (mx < 0 || mx >= window.innerWidth) return
    if (my < 0 || my >= window.innerHeight) return
    fb.resize(window.innerWidth, window.innerHeight)
    regl.clear({ color: [0,0,0,1], depth: true, framebuffer: fb })
    var res = null
    draw({ framebuffer: fb }, function () {
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
