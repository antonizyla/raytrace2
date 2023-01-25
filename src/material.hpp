#ifndef raytrace2_material_hpp
#define raytrace2_material_hpp
#include <cstdlib>
#pragma once

#include "hittable.hpp"
#include "ray.hpp"
#include "vec3.hpp"

struct hit_record;

struct scatter_record {
    ray scatter_ray;
    colour attenuation;
    hit_record hit_rec;
};

class material {
  public:
    virtual bool scatter(const ray &r, hit_record &rec, colour &attenuation,
                         ray &scattered) const = 0;
};

class lambertian : public material {
  public:
    lambertian(const colour &a) : albedo(a) {}

    virtual bool scatter(const ray &r, hit_record &rec, colour &attenutation,
                         ray &scattered) const override {
        auto scatter_direction = rec.normal + random_unit_vec3();
        scattered = ray(rec.point, scatter_direction);
        attenutation = albedo;
        return true;
    }

  public:
    colour albedo;
};

#endif
