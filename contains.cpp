#include <string>
#include <set>

// https://rules.sonarsource.com/cpp/tag/since-c++20/RSPEC-6171
namespace pre_cpp20 {
    void contains() {

        std::set<std::string> numbers = {"one", "two", "three"};

        if( numbers.find( "two" ) != numbers.end()) {
            // ...
        }
    }
}

namespace cpp20 {
    void contains() {

        std::set<std::string> numbers = {"one", "two", "three"};

        if( numbers.contains( "two" ) ) {
            // ...
        }
    }
}
