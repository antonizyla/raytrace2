#ifndef raytrace2_image_hpp
#define raytrace2_image_hpp

#include "colour.hpp"
#include <array>
#include <cstdint>
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb/stb_image_write.h"

class image {
  public:
    int height = 0;
    int width = 0;
    std::vector<std::array<uint8_t, 3>> data;

  public:
    image(int width, int height) : height(height), width(width) {
        data.resize(width * height);
    }

    image() {}

    void initialise(int _width, int _height) {
        height = _height;
        width = _width;
        data.resize(width * height);
    }

    // set pixel colours, top left is (0, 0)
    void set_pixel(int x, int y, const colour &c) {
        data[y * width + x][0] = c.x();
        data[y * width + x][1] = c.y();
        data[y * width + x][2] = c.z();
    }

    void write(const char *filename = "image.jpg") {
        stbi_write_bmp(filename, width, height, 3, &data[0]);
    }
};

#endif // !raytrace2_image_hpp
