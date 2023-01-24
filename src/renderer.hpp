#ifndef raytrace2_renderer_hpp
#define raytrace2_renderer_hpp

#include <complex>
#include <cstdint>
#include <iostream>

#include "colour.hpp"
#include "hittable.hpp"
#include "image.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "utility.hpp"
#include "vec3.hpp"

inline colour rayColour(const ray &r, const hittable &environment) {
    // auto hit_info = sphere(0.5, vec3(0, 0, -1)).hit(r, 0, infinity);
    //  std::cout << (int)(255.99 * 0.8) << std::endl;
    // if (hit_info.hit) {
    //   auto normal =
    //     vec3(r.at(hit_info.rec.lambda) - vec3(0, 0, -1)).unit_vector();
    // return 0.5 * colour(normal.x() + 1, normal.y() + 1, normal.z() + 1);
    // }
    auto hit = environment.hit(r, 0, infinity);
    if (hit.hit) {
        auto normal = vec3(r.at(hit.rec.lambda) - vec3(0, 0, -1)).unit_vector();
        return 0.5 * colour(normal.x() + 1, normal.y() + 1, normal.z() + 1);
    }
    return vec3(0.5, 0.5, 0.5);
}

class renderer {
  public:
    // image
    int img_width;
    int img_height;
    double view_width = 3.5;
    double view_height;
    double fov;
    double aspect_ratio = 16.0 / 9.0;
    image img;

    // camera
    vec3 cam_origin = vec3(0, 0, 0);
    vec3 cam_x;
    vec3 cam_y;
    vec3 top_left_corner;
    double focal_length = 1.0;

    // scene
    hittable_list scene;

    renderer(int width, double fov);

    void render();
};

inline void renderer::render() {
    for (int y = 0; y < img_height; ++y) {
        for (int x = 0; x < img_width; ++x) {
            double proportion_x = double(x) / double(img_width - 1);
            double proportion_y = double(y) / double(img_height - 1);
            auto r = ray(vec3(0, 0, 0), top_left_corner + cam_x * proportion_x -
                                            cam_y * proportion_y - cam_origin);
            img.set_pixel(x, y, col_to_8bit(rayColour(r, scene)));
        }
    }

    img.write("output.jpg");
}

inline renderer::renderer(int _width, double _fov) {
    img_width = _width;
    img_height = (uint32_t)(img_width / aspect_ratio);
    fov = _fov;
    view_height = view_width / aspect_ratio;
    cam_x = vec3(view_width, 0, 0);
    cam_y = vec3(0, view_height, 0);
    top_left_corner =
        cam_origin - cam_x / 2 + cam_y / 2 - vec3(0, 0, focal_length);
    img.initialise(img_width, img_height);

    scene.add(std::make_shared<sphere>(0.5, vec3(0, 0, -1)));
}

#endif // raytrace2_renderer_hpp
