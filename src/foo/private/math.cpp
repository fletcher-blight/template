#include <foo/math.hpp>

#include <limits>
#include <algorithm>

static auto safe_long_to_int(
    long const value)
    -> int
{
    auto const res = std::clamp<long>(
        value,
        std::numeric_limits<int>::min(),
        std::numeric_limits<int>::max());
    return static_cast<int>(res);
}

auto foo::math::add(
    int const a,
    int const b)
    noexcept
    -> int
{
    long const res = a + b;
    return safe_long_to_int(res);
}

// Unit testing support
#ifdef BUILD_TESTING
#include <gtest/gtest.h>

TEST(foo_math_unit_safe_long_to_int, zeros)
{
    EXPECT_EQ(safe_long_to_int(0), 0);
}

#endif // BUILD_TESTING