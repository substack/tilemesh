#pragma glslify: forward = require('glsl-proj4/tmerc/forward')
#pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
vec3 geom (proj_t proj, vec2 pos, vec3 width, float expand, float angle, float aspect) {
  vec3 p = forward(proj,pos)*vec3(1,aspect,1);
  vec2 adir = vec2(cos(angle),sin(angle))*0.001;
  vec3 np = forward(proj,pos+adir)*vec3(1,aspect,1);
  vec3 dir = normalize(np-p);
  float rex = sqrt(proj.k0/width.z*300000.0);
  float scale = max(width.x,width.y*proj.k0)
    + min(0.005,min(sqrt(proj.k0*2.0),expand*rex*step(0.7,rex)));
  return vec3((p+dir*scale).xy,1.0-1.0/width.z);
}
#pragma glslify: export(geom)
