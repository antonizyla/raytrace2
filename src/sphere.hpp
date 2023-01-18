#ifndef raytrace2_sphere_hpp
#define raytrace2_sphere_hpp

#include "vec3.hpp"
#include "ray.hpp"

class sphere {
public:
    double radius;
    vec3 center;
public:
    sphere(double radius, vec3 center) : radius(radius), center(center) {}

    bool hit(const ray &r);
};

bool sphere::hit(const ray &r) {
    // (P−C)⋅(P−C)−r2+2tU⋅(P−C)+t2(U⋅U)=0
    // https://math.stackexchange.com/questions/1939423/calculate-if-vector-intersects-sphere
    vec3 oc = r.get_origin() - center;
    double a = dot(r.get_direction(), r.get_direction());
    double b = 2 * dot(oc, r.get_direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

#endif //raytrace2_sphere_hpp
