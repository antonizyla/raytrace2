#ifndef raytrace2_utility_hpp
#define raytrace2_utility_hpp

#include <limits>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#endif // !_utility_hpp
