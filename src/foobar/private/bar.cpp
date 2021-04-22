#include <foo/bar.hpp>

#include <limits>
#include <spdlog/spdlog.h>

static auto can_double(
    int const x)
    -> bool
{
    spdlog::info("Can Double {}", x);
    auto constexpr max = std::numeric_limits<int>::max() / 2;
    return x <= max;
}

auto foo::bar(
    int const x)
    -> int
{
    return can_double(x) ? x * 2 : std::numeric_limits<int>::max();
}

#if TESTING
#include <gtest/gtest.h>
TEST(Foobar, bar)
{
    EXPECT_TRUE(can_double(0));
    EXPECT_TRUE(can_double(100));
    EXPECT_TRUE(can_double(1000000000));
    EXPECT_TRUE(not can_double(1100000000));
}
#endif