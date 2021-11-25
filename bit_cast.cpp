#include <cstring>
#include <cstdint>

// https://rules.sonarsource.com/cpp/RSPEC-6181

namespace pre_cpp20 {

    uint32_t using_memcpy() {

        static_assert( sizeof( float ) == sizeof( uint32_t ));
        float const src = 1.0f;
        uint32_t dst;
        std::memcpy( &dst, &src, sizeof( float ));
        return dst;

    }
}

//#include "pf_bit.h"
#include <bit>

namespace cpp20 {
    uint32_t using_bitcast() {

        float const src = 1.0f;
        auto dst = std::bit_cast<uint32_t>( src );
        return dst;

    }
}
