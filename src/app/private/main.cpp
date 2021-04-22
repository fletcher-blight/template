#include <foo/bar.hpp>

#include <string>
#include <iostream>

static auto get_int() -> int {
    int x = 0;
    std::cin >> x;
    return x;
}

static auto to_string(int const x) -> std::string {
    return "double: " + std::to_string(x);
}

#if not TESTING
int main()
{
    while (true) {
        auto const x = get_int();
        if (x == 0) break;
        auto const d = foo::bar(x);
        std::cout << to_string(d) << '\n';
    }
    return 0;
}
#endif

#if TESTING
#include <gtest/gtest.h>
TEST(App, main)
{
    EXPECT_EQ(to_string(5), std::string("double: 5"));
}
#endif