var glsl = require('glslify')
var dmerge = require('deep-assign')

var widths = {
  'width[0]': [0.005,100.0,1],
  'width[1]': [0.004,90.0,2],
  'width[2]': [0.003,80.0,3],
  'width[3]': [0.002,70.0,4],
  'width[4]': [0.001,60.0,5],
  'width[5]': [0.0009,40.0,6],
  'width[6]': [0.0008,30.0,7],
  'width[7]': [0.0007,25.0,8],
  'width[8]': [0.0006,22.5,9],
  'width[9]': [0.0005,21.0,10],
  'width[10]': [0.0004,20.0,11],
  'width[11]': [0.0003,17.5,12],
  'width[12]': [0.0002,15.0,13],
  'width[13]': [0.0001,12.5,14],
  'width[14]': [0.00009,11.0,15],
  'width[15]': [0.00008,10.0,16],
  'width[16]': [0.00007,9.0,17],
  'width[17]': [0.00006,8.0,18],
  'width[18]': [0.00005,7.0,19]
}
var colors = {
  'colors[0]': [1,0,0],
  'colors[1]': [1,0.8,0],
  'colors[2]': [1,0.6,0],
  'colors[3]': [1,0.4,0.3],
  'colors[4]': [1,0.3,0.5],
  'colors[5]': [0.8,0.8,0.8],
  'colors[6]': [0.8,0.8,0.8],
  'colors[7]': [0.8,0.8,0.8],
  'colors[8]': [0.8,0.8,0.8],
  'colors[9]': [0.8,0.8,0.8],
  'colors[10]': [0.8,0.8,0.8],
  'colors[11]': [0.8,0.8,0.8],
  'colors[12]': [0.8,0.8,0.8],
  'colors[13]': [0.8,0.8,0.8],
  'colors[14]': [0.8,0.8,0.8],
  'colors[15]': [0.8,0.8,0.8],
  'colors[16]': [0.8,0.8,0.8],
  'colors[17]': [0.8,0.8,0.8],
  'colors[18]': [0.8,0.8,0.8]
}
var borderColors = {}
Object.keys(colors).forEach(function (key) {
  borderColors[key] = [0,0,0]
})
var borderWidths = {}
Object.keys(widths).forEach(function (key) {
  borderWidths[key] = widths[key].slice()
  borderWidths[key][2] += 20
})

function draw (params) {
  return {
    frag: `
      precision highp float;
      varying vec4 vcolor;
      void main () {
        gl_FragColor = vcolor;
      }
    `,
    uniforms: Object.assign(params.camera.members('proj'), widths, {
      aspect: function (context) {
        return context.viewportWidth / context.viewportHeight
      },
    }),
    attributes: {
      position: params.mesh.positions,
      angle: params.mesh.angles,
      roadtype: params.mesh.types
    },
    elements: params.mesh.cells
  }
}

exports.click = function (regl, params) {
  return regl(dmerge(draw(params), {
    vert: glsl`
      precision highp float;
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      #pragma glslify: geom = require('./highway-geom.glsl')
      uniform proj_t proj;
      attribute vec2 position, id;
      attribute float angle, roadtype;
      uniform float aspect;
      varying vec4 vcolor;
      uniform vec3 width[19];
      void main () {
        vcolor = vec4(id,0,1);
        float expand = 0.01;
        vec3 p = geom(proj,position,width[int(roadtype)],expand,angle,aspect);
        gl_Position = vec4(p,1);
      }
    `,
    attributes: {
      id: params.mesh.ids
    },
    framebuffer: regl.prop('framebuffer')
  }))
}

exports.draw = function (regl, params) {
  var ropts = {
    vert: glsl`
      precision highp float;
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      #pragma glslify: geom = require('./highway-geom.glsl')
      uniform proj_t proj;
      attribute vec2 position, id;
      attribute float angle, roadtype;
      uniform float aspect;
      uniform vec3 colors[19];
      uniform vec3 width[19];
      uniform float expand;
      uniform vec2 selected, hover;
      varying vec4 vcolor;
      void main () {
        vec3 w = width[int(roadtype)];
        if (length(selected) > 0.1 && length(selected-id) < 0.1) {
          vcolor = vec4(1,1,1,1);
        } else if (length(hover) > 0.1 && length(hover-id) < 0.1) {
          vcolor = vec4(pow(colors[int(roadtype)]*0.5+vec3(0,0.8,0),vec3(2.2)),1);
        } else {
          vcolor = vec4(pow(colors[int(roadtype)],vec3(2.2)),1);
        }
        gl_Position = vec4(geom(proj,position,w,expand,angle,aspect),1);
      }
    `,
    attributes: {
      id: params.mesh.ids
    },
    uniforms: {
      selected: function () { return params.state.selected },
      hover: function () { return params.state.hover },
    }
  }
  var drawLines = regl(dmerge(draw(params), ropts, {
    uniforms: Object.assign({ expand: 0 }, colors)
  }))
  var drawBorders = regl(dmerge(draw(params), ropts, {
    uniforms: Object.assign({ expand: 0.005 }, borderWidths, borderColors)
  }))
  var labelmesh = { positions: [], cells: [], offsets: [] }
  var widths = {}
  Object.keys(params.labels).forEach(function (id) {
    var label = params.labels[id]
    var name = label[0]
    var lon = label[1], lat = label[2]
    var theta = (Math.PI*5/2 + label[3]) % Math.PI - Math.PI/2
    var chars = name.split('')
    var width = 0
    chars.forEach(function (c) {
      var m = params.characters[c]
      for (var i = 0; i < m.cells.length; i++) {
        var c = m.cells[i]
        labelmesh.cells.push(c.map(function (x) {
          return x+labelmesh.positions.length
        }))
      }
      var xmin = Infinity, xmax = -Infinity
      var space = 0.2
      for (var i = 0; i < m.positions.length; i++) {
        var p = m.positions[i]
        xmin = Math.min(xmin,p[0])
        xmax = Math.max(xmax,p[0])
        var x = p[0]+width+space*0.5
        var y = -p[1]-1.2
        var xr = x*Math.cos(theta)-y*Math.sin(theta)
        var yr = x*Math.sin(theta)+y*Math.cos(theta)
        labelmesh.positions.push([xr,yr])
        labelmesh.offsets.push([lon,lat])
      }
      if (!widths[c] && xmax > -Infinity) {
        widths[c] = xmax-xmin
      } else if (!widths[c]) widths[c] = 0.75
      width += widths[c] + space
    })
  })
  var drawLabels = regl({
    frag: `
      precision mediump float;
      uniform vec3 color;
      void main () {
        gl_FragColor = vec4(color,1);
      }
    `,
    vert: glsl`
      precision highp float;
      #pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
      #pragma glslify: forward = require('glsl-proj4/tmerc/forward')
      attribute vec2 position, offset;
      uniform float aspect, expand;
      uniform proj_t proj;
      void main () {
        gl_Position = vec4(
          (forward(proj,offset)+vec3(position*expand*0.02,0))
            * vec3(1,aspect,1),1);
      }
    `,
    uniforms: Object.assign(params.camera.members('proj'), widths, {
      aspect: function (context) {
        return context.viewportWidth / context.viewportHeight
      },
      expand: regl.prop('expand'),
      color: regl.prop('color')
    }),
    attributes: {
      position: labelmesh.positions,
      offset: labelmesh.offsets
    },
    depth: { enable: false, mask: false },
    elements: labelmesh.cells
  })
  return function (props) {
    drawLines(props)
    drawBorders(props)
    drawLabels({ expand: 1.01, color: [1,0.5,0] })
    drawLabels({ expand: 1, color: [0,1,0] })
  }
}
