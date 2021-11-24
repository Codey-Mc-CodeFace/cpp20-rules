// https://rules.sonarsource.com/cpp/RSPEC-6179

#include <iostream>
#include <numeric>
#include <cmath>

namespace pre_cpp20 {
    void midpoint( int a, int b ) {

        auto m1 = (a + b) / 2;
        auto m2 = a + (b - a) / 2;

        std::cout << m1 << m2;
    }

    void lerp( float a, float b ) {

        auto i1 = a + (b - a) * 0.3f;
        auto i2 = a + (b - a) / 3;


        std::cout << i1 << i2;
    }
}

namespace cpp20 {
    void midpoint( int a, int b ) {

        auto m = std::midpoint( a, b);

        std::cout << m;
    }

    void lerp( float a, float b ) {

        auto i1 = std::lerp( a, b, 0.3f);
        auto i2 = std::lerp( a, b, 1 / .3f);

        std::cout << i1 << i2;
    }
}
