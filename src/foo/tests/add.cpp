#include <foo/math.hpp>
#include <gtest/gtest.h>

TEST(foo_math_add, zeros)
{
    EXPECT_EQ(foo::math::add(0, 0), 0);
}