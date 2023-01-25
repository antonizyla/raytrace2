#ifndef raytrace2_vec3_hpp
#define raytrace2_vec3_hpp

#include "utility.hpp"
#include <cmath>
#include <iostream>

class vec3 {
  private:
    double points[3];

  public:
    vec3() : points{0, 0, 0} {}
    vec3(double x, double y, double z) : points{x, y, z} {}

    double magnitude() const {
        return sqrt(points[0] * points[0] + points[1] * points[1] +
                    points[2] * points[2]);
    }

    double magnitude_squared() const {
        return points[0] * points[0] + points[1] * points[1] +
               points[2] * points[2];
    }

    vec3 unit_vector() const {
        double mag = magnitude();
        return {points[0] / mag, points[1] / mag, points[2] / mag};
    }

    vec3 &operator+=(const vec3 &a) {
        points[0] += a.points[0];
        points[1] += a.points[1];
        points[2] += a.points[2];
        return *this;
    }

    vec3 operator*=(const double lambda) {
        points[0] *= lambda;
        points[1] *= lambda;
        points[2] *= lambda;
        return *this;
    }

    bool operator==(const vec3 &a) const {
        return points[0] == a.points[0] && points[1] == a.points[1] &&
               points[2] == a.points[2];
    }

    void print() {
        std::cout << "(" << points[0] << ", " << points[1] << ", " << points[2]
                  << ")" << std::endl;
    }

    bool near_zero() const {
        const double s = 1e-8;
        return (fabs(x()) < s) && (fabs(y()) < s) && (fabs(z()) < s);
    }

    double x() const { return points[0]; }
    double y() const { return points[1]; }
    double z() const { return points[2]; }
};

using colour = vec3;

inline vec3 random_vec3() { return {random_d(), random_d(), random_d()}; }

inline vec3 random_vec3(double min, double max) {
    return {random_d(min, max), random_d(min, max), random_d(min, max)};
}

inline vec3 random_unit_vec3() { return random_vec3(-1, 1).unit_vector(); }

inline vec3 random_unit_sphere_vec3() {
    while (true) {
        auto p = random_vec3(-1, 1);
        if (p.magnitude_squared() >= 1)
            continue;
        return p;
    }
}

inline vec3 operator+(const vec3 &a, const vec3 &b) {
    return {a.x() + b.x(), a.y() + b.y(), a.z() + b.z()};
}

inline vec3 operator-(const vec3 &a, const vec3 &b) {
    return {a.x() - b.x(), a.y() - b.y(), a.z() - b.z()};
}

inline vec3 operator*(const double lambda, const vec3 &a) {
    return {a.x() * lambda, a.y() * lambda, a.z() * lambda};
}

inline vec3 operator*(const vec3 &a, const double lambda) {
    return {a.x() * lambda, a.y() * lambda, a.z() * lambda};
}

inline vec3 operator/(const vec3 &a, const double lambda) {
    return a * (1 / lambda);
}

inline double dot(const vec3 &a, const vec3 &b) {
    return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}

inline vec3 cross(const vec3 &a, const vec3 &b) {
    return {a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
            a.x() * b.y() - a.y() * b.x()};
}

inline vec3 reflect(const vec3 &v, const vec3 &n) {
    return v - 2 * dot(v, n) * n;
}

inline vec3 operator*(const vec3 &a, const vec3 &b) {
    return {a.x() * b.x(), a.y() * b.y(), a.z() * b.z()};
}

inline vec3 random_unit_hemisphere_vec3(const vec3 &normal) {
    vec3 in_unit_sphere = random_unit_sphere_vec3();
    if (dot(in_unit_sphere, normal) > 0.0) {
        return in_unit_sphere;
    } else {
        return in_unit_sphere * -1;
    }
}
#endif // !raytrace2_vec3_hpp
