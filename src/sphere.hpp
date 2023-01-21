#ifndef raytrace2_sphere_hpp
#define raytrace2_sphere_hpp

#include "ray.hpp"
#include "vec3.hpp"

class sphere {
  public:
    double radius;
    vec3 center;

  public:
    sphere(double radius, vec3 center) : radius(radius), center(center) {}

    double hit(const ray &r);
};

inline double sphere::hit(const ray &r) {
    // (P−C)⋅(P−C)−r2+2tU⋅(P−C)+t2(U⋅U)=0
    // https://math.stackexchange.com/questions/1939423/calculate-if-vector-intersects-sphere
    vec3 oc = r.get_origin() - center;
    double a = dot(r.get_direction(), r.get_direction());
    double b = 2.0 * dot(oc, r.get_direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        return (-b - sqrt(discriminant)) / (2.0 * a);
    }
    return -1.0;
}

#endif // raytrace2_sphere_hpp
