#include "gtest/gtest.h"

#include "ray.hpp"
#include "vec3.hpp"

TEST(RayTest, RayTest) {
    ray r(vec3(1, 2, 3), vec3(4, 5, 6));
    EXPECT_EQ(r.get_origin(), vec3(1, 2, 3));
    EXPECT_EQ(r.get_direction(), vec3(4, 5, 6));
}

TEST(RayTest, RayAtTest) {
    ray r(vec3(1, 2, 3), vec3(4, 5, 6));
    EXPECT_EQ(r.at(0), vec3(1, 2, 3));
    EXPECT_EQ(r.at(1), vec3(5, 7, 9));
    EXPECT_EQ(r.at(2), vec3(9, 12, 15));
}
