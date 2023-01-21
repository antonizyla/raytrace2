#ifndef raytrace2_colour_hpp
#define raytrace2_colour_hpp

#include "vec3.hpp"
#include <cstdint>

inline colour col_to_8bit(const colour &c) {
    return {(uint8_t)255.9 * c.x(), (uint8_t)255.9 * c.y(), (uint8_t)255.9 * c.z()};
}

#endif // !raytrace2_colour_hpp
