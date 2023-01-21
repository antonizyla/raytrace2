#ifndef raytrace2_camera_hpp
#define raytrace2_camera_hpp

#include "ray.hpp"
#include "vec3.hpp"

class camera {
  public:
    vec3 origin;
    double focal_length;
};
#endif // !DEBUG
