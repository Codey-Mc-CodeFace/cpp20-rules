#include <string>

// https://rules.sonarsource.com/cpp/tag/since-c++20/RSPEC-6178

namespace pre_cpp20 {
    void starts_with_ends_with() {

        std::string s = "long and winding road";

        if( s.substr( 0, 4 ) == "long" &&
            s.size() > 4 && s.substr( s.size() - 4 ) == "road" ) {
            // ...
        }
    }
}

namespace cpp20 {
    void starts_with_ends_with() {

        std::string s = "long and winding road";

        if( s.starts_with("long") && s.ends_with("road") ) {
            // ...
        }
    }
}
