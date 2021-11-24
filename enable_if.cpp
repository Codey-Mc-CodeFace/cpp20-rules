#include <type_traits>
#include <concepts>
//#include "pf_concepts.h"

namespace pre_cpp20 {
    template<typename N, class = typename std::enable_if<std::is_integral_v<N> && std::is_signed_v<N>>::type>
    auto negate( N n ) { return -n; }
}

namespace cpp20_1 {
    template<std::signed_integral N>
    auto negate( N n ) { return -n; }
}

namespace cpp20_2 {
    auto negate( std::signed_integral auto n ) { return -n; }
}

// https://rules.sonarsource.com/cpp/RSPEC-6195

void test_enable_if() {
    pre_cpp20::negate( -1 );
    cpp20_1::negate( -1 );
    cpp20_2::negate( -1 );
}