#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

// https://rules.sonarsource.com/cpp/tag/since-c++20/RSPEC-6165

namespace pre_cpp20 {
    void remove_empty_strings( std::vector<std::string>& v ) {

        v.erase(std::remove( v.begin(), v.end(), std::string()), v.end());

    }
    void remove_empty_strings2( std::vector<std::string>& v ) {

        // In case you first took the suggestion to use ranges::remove ...

        v.erase(std::ranges::remove( v, std::string()).begin(), v.end());

    }
    void remove_bad_strings( std::vector<std::string>& v ) {

        v.erase(std::remove_if( v.begin(), v.end(), []( auto s ) { return s == "bad"; } ), v.end());

    }

    void remove_bad_strings( std::unordered_set<std::string, std::string>& m ) {

        auto it = m.begin();
        while( it != m.end() ) {
            if( *it == "bad" ) {
                it = m.erase( it );
            } else {
                ++it;
            }
        }
    }

}

namespace cpp20 {
    void remove_empty_strings( std::vector<std::string>& v ) {

        std::erase(v, std::string());

    }

    void remove_bad_strings( std::vector<std::string>& v ) {

        std::erase_if(v, []( auto s ) { return s == "bad"; } );

    }

    void remove_bad_strings( std::unordered_set<std::string, std::string>& strings ) {

        std::erase_if(strings, []( auto s ) { return s == "bad"; } );

    }

}
