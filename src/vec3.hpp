#ifndef raytrace2_vec3_hpp
#define raytrace2_vec3_hpp

#include <cmath>

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
        return vec3(points[0] / mag, points[1] / mag, points[2] / mag);
    }

    vec3 &operator+=(const vec3 &a) {
        points[0] += a.points[0];
        points[1] += a.points[1];
        points[2] += a.points[2];
        return *this;
    }

    vec3 &operator*=(const double lambda) {
        points[0] *= lambda;
        points[1] *= lambda;
        points[2] *= lambda;
        return *this;
    }

    bool operator==(const vec3 &a) const {
        return points[0] == a.points[0] && points[1] == a.points[1] &&
               points[2] == a.points[2];
    }

    double x() const { return points[0]; }
    double y() const { return points[1]; }
    double z() const { return points[2]; }
};

inline vec3 operator+(const vec3 &a, const vec3 &b) {
    return vec3(a.x() + b.x(), a.y() + b.y(), a.z() + b.z());
}

inline vec3 operator*(const vec3 &a, const double lambda) {
    return vec3(a.x() * lambda, a.y() * lambda, a.z() * lambda);
}

inline vec3 operator*(const vec3 &a, const vec3 &b) {
    return vec3(a.x() * b.x(), a.y() * b.y(), a.z() * b.z());
}

inline vec3 operator/(const vec3 &a, const double lambda) {
    return a * (1 / lambda);
}

inline double dot(const vec3 &a, const vec3 &b) {
    return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}

inline vec3 cross(const vec3 &a, const vec3 &b) {
    return vec3(a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
                a.x() * b.y() - a.y() * b.x());
}

#endif // !raytrace2_vec3_hpp