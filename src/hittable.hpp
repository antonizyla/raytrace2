#ifndef raytrace2_hittable_hpp
#define raytrace2_hittable_hpp

#include "ray.hpp"
#include <memory>
#include <vector>

enum material_type { diffuse, metal, dielectric };

struct hit_record {
    vec3 point;
    vec3 normal;
    double lambda;
};

struct hit_info {
    hit_record rec;
    bool hit;
};

class hittable {
  public:
    // hit record pair holds bool if they are hit and data about the hit
    virtual hit_info hit(const ray &r, const double &tmin,
                         const double &tmax) const = 0;
};

// gives hittable list a hit method which will allow for all of the objects to
// be checked
class hittable_list : public hittable {
  private:
    std::vector<std::shared_ptr<hittable>> objects;

  public:
    hittable_list(){};

    void add(std::shared_ptr<hittable> obj) { objects.push_back(obj); };

    hit_info hit(const ray &r, const double &tmin,
                 const double &tmax) const override;

    void clear_objects() { objects.clear(); };
};

inline hit_info hittable_list::hit(const ray &r, const double &tmin,
                                   const double &tmax) const {
    double current_closest = tmax;
    hit_info hit;
    hit.hit = false;

    for (auto &object : objects) {
        auto hit_tmp = object->hit(r, tmin, tmax);
        if (hit_tmp.hit) {
            if (hit_tmp.rec.lambda < current_closest) {
                hit = hit_tmp;
                current_closest = hit_tmp.rec.lambda;
            }
        }
    }
    return hit;
}

#endif // !raytrace2_hittable_hpp
