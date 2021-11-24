#include <string>
#include <iostream>

struct Empty {};

namespace pre_cpp20 {
    struct SomeClass {
        int theAnswer = 42;
        std::string name;
        Empty empty;
    };
}

namespace cpp20 {
    struct SomeClass {
        int theAnswer = 42;
        std::string name;
        [[no_unique_address]] Empty empty;
    };
}


void test_no_unique_address() {
    pre_cpp20::SomeClass sc;
    if( sizeof( pre_cpp20::SomeClass::empty ) > 0 )
        std::cout << sc.theAnswer << sc.name;

    cpp20::SomeClass sc2;
    if( sizeof( cpp20::SomeClass::empty ) > 0 )
        std::cout << sc2.theAnswer << sc2.name;
}
