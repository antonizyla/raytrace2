#include "../lib/googletest/googletest/include/gtest/gtest.h"

#include "vec3.hpp"

TEST(Vec3Test, Magnitude) {
    vec3 v(1, 2, 3);
    EXPECT_EQ(v.magnitude(), sqrt(14));
}

TEST(Vec3Test, MagnitudeSquared) {
    vec3 v(1, 2, 3);
    EXPECT_EQ(v.magnitude_squared(), 14);
}

TEST(Vec3Test, UnitVector) {
    vec3 v(1, 2, 3);
    vec3 unit = v.unit_vector();
    EXPECT_EQ(unit.magnitude(), 1);
}

TEST(Vec3Test, Add) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);
    vec3 res(5, 7, 9);
    v1 += v2;
    EXPECT_EQ(v1, res);
}

TEST(Vec3Test, DotProduct) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);
    EXPECT_EQ(dot(v1, v2), 32);
}

TEST(Vec3Test, CrossProduct) {
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);
    vec3 res(-3, 6, -3);
    EXPECT_EQ(cross(v1, v2), res);
}

TEST(Vec3Test, Equality) {
    vec3 v1(1, 2, 3);
    vec3 v2(1, 2, 3);
    vec3 v3(4, 5, 6);
    EXPECT_EQ(v1, v2);
    EXPECT_NE(v1, v3);
}

TEST(Vec3Test, Multiplication){
    vec3 v1(1, 2, 3);
    vec3 res(4, 8, 12);
    EXPECT_EQ(v1 * 4, res);
}

TEST(Vec3Test, Division){
    vec3 v1(1, 2, 3);
    vec3 res(0.5, 1, 1.5);
    EXPECT_EQ(v1 / 2, res);
}

TEST(Vec3Test, Subtraction){
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);
    vec3 res(-3, -3, -3);
    EXPECT_EQ(v1 - v2, res);
}

