#ifndef raytrace2_ray_hpp
#define raytrace2_ray_hpp

#include "vec3.hpp"

class ray {
  public:
    ray() {}

    ray(vec3 origin, vec3 direction) : origin(origin), direction(direction) {}

    vec3 get_direction() const { return direction; }

    vec3 get_origin() const { return origin; }

    vec3 at(double lambda) const { return origin + direction * lambda; }

  private:
    vec3 origin;
    vec3 direction;
};

#endif // raytrace2_ray_hpp
