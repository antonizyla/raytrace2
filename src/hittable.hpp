#ifndef raytrace2_hittable_hpp
#define raytrace2_hittable_hpp

#include "ray.hpp"

struct hit_record {
    vec3 point;
    vec3 normal;
};

class hittable {
  public:
    virtual bool hit(const ray &r, const hit_record &rec) const = 0;
};

#endif // !raytrace2_hittable_hpp
