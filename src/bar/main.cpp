#include <foo/math.hpp>
#include <iostream>

int main()
{
    while (true) {
        int a = 0;
        int b = 0;
        std::cout << "> ";
        std::cin >> a >> b;
        int const c = foo::math::add(a, b);
        std::cout << c << '\n';
    }

    return 0;
}