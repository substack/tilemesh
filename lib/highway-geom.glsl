#pragma glslify: forward = require('glsl-proj4/tmerc/forward')
#pragma glslify: proj_t = require('glsl-proj4/tmerc/t')
vec3 geom (proj_t proj, vec2 pos, float roadtype, float angle, float aspect) {
  vec3 p = forward(proj,pos)*vec3(1,aspect,1);
  vec2 adir = vec2(cos(angle),sin(angle))*0.001;
  vec3 np = forward(proj,pos+adir)*vec3(1,aspect,1);
  vec3 dir = normalize(np-p);
  return vec3((p+dir
    * max(0.005*pow(1.0/roadtype,1.2),proj.k0*(40.0-roadtype*2.0))
      * step(1e-6,proj.k0/roadtype)).xy,
    1.0-1.0/roadtype);
}
#pragma glslify: export(geom)
