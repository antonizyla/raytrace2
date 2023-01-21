#ifndef raytrace2_renderer_hpp
#define raytrace2_renderer_hpp

#include <complex>
#include <cstdint>
#include <iostream>

#include "image.hpp"
#include "ray.hpp"
#include "vec3.hpp"

class renderer {
  public:
    // image
    int width;
    int height;
    double fov;
    double aspect_ratio = 16.0 / 9.0;
    image img;

    // camera
    vec3 cam_origin = vec3(0, 0, 0);
    vec3 cam_x;
    vec3 cam_y;
    vec3 top_left_corner;
    double focal_length = 1.0;

    renderer(int width, double fov);

    void render();
};

void renderer::render() {
    std::cout << "Rendering..." << std::endl;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double u = double(x) / double(width);
            double v = double(y) / double(height);

            auto r = ray(vec3(0, 0, 0),
                         top_left_corner + cam_x * u + cam_y * v - cam_origin);
            const uint8_t colour[3] = {0, 255, 255};
            img.set_pixel(x, y, colour);
        }
    }

    img.write("output.jpg");
}

inline renderer::renderer(int _width, double _fov) {
    width = _width;
    height = (uint32_t)(width / aspect_ratio);
    fov = _fov;
    cam_x = vec3(width, 0, 0);
    cam_y = vec3(0, height, 0);
    top_left_corner =
        cam_origin - cam_x / 2 + cam_y / 2 - vec3(0, 0, focal_length);
    img.initialise(width, height);
}

#endif // raytrace2_renderer_hpp
