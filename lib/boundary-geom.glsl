#pragma glslify: forward = require('glsl-proj4/tmerc/forward')
#pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
vec3 geom (proj_t proj, vec2 pos, float angle, float aspect) {
  vec3 p = forward(proj,pos)*vec3(1,aspect,1);
  vec2 adir = vec2(cos(angle),sin(angle))*0.001;
  vec3 np = forward(proj,pos+adir)*vec3(1,aspect,1);
  vec3 dir = normalize(np-p);
  return vec3((p+dir*clamp(proj.k0*50.0,0.001,0.05)).xy,1.0-1.0/50.0);
}
#pragma glslify: export(geom)
