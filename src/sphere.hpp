#ifndef raytrace2_sphere_hpp
#define raytrace2_sphere_hpp

#include "hittable.hpp"
#include "ray.hpp"
#include "utility.hpp"
#include "vec3.hpp"

class sphere : public hittable {
  public:
    double radius;
    vec3 center;

  public:
    sphere(double radius, vec3 center) : radius(radius), center(center) {}

    hit_info hit(const ray &r, const double &tmin,
                 const double &tmax) const override;
};

inline hit_info sphere::hit(const ray &r, const double &t_min,
                            const double &t_max) const {
    hit_info hit;

    // (P−C)⋅(P−C)−r2+2tU⋅(P−C)+t2(U⋅U)=0
    // https://math.stackexchange.com/questions/1939423/calculate-if-vector-intersects-sphere
    vec3 oc = r.get_origin() - center;
    double a = r.get_direction().magnitude_squared();
    double b_half = dot(oc, r.get_direction());
    double c = oc.magnitude_squared() - radius * radius;
    double discriminant = b_half * b_half - a * c;

    if (discriminant < 0) {
        hit.hit = false;
        return hit;
    }

    double sqrt_discriminant = sqrt(discriminant);

    // values of t determine how for away to select intersections from the
    // camera, also maximum distance away to count an intersection

    double lambda_to_root = (-b_half - sqrt_discriminant) / (a);
    if (lambda_to_root < t_min || lambda_to_root > t_max) {
        lambda_to_root = (-b_half + sqrt_discriminant) / (a);
        if (lambda_to_root < t_min || lambda_to_root > t_max) {
            hit.hit = false;
            return hit;
        }
    }

    hit.rec.lambda = lambda_to_root;
    hit.rec.point = r.at(hit.rec.lambda);
    hit.rec.normal = (hit.rec.point - center) / radius;
    hit.hit = true;
    return hit;
}

#endif // raytrace2_sphere_hpp
