#include <vector>
#include <span>
#include <iostream>


struct Droid;

std::vector<Droid*> get_suspicious_droids();

// https://rules.sonarsource.com/cpp/tag/since-c++20/RSPEC-6188
namespace pre_cpp20 {
    bool looking_for_these( std::vector<Droid const*> const& droids );

    void use_the_force() {

        std::vector<Droid*> droids = get_suspicious_droids();

        if( !looking_for_these( std::vector<Droid const*>{ droids.begin(), droids.end() } ) ) {
            std::cout << "these are not the droids you're looking for\n";
        }
    }
}

//https://rules.sonarsource.com/cpp/tag/since-c++20/RSPEC-6231
namespace cpp20_1 {
    bool looking_for_these( std::span<Droid const* const> droids );

    void use_the_force() {

        auto droids = get_suspicious_droids();

        if( !looking_for_these( std::vector<Droid const*>{ droids.begin(), droids.end() } )) {
            std::cout << "these are not the droids you're looking for\n";
        }
    }
}

namespace cpp20_2 {
    bool looking_for_these( std::span<Droid const* const> droids );

    void use_the_force() {

        auto droids = get_suspicious_droids();

        if( !looking_for_these( droids ) ) {
            std::cout << "these are not the droids you're looking for\n";
        }
    }
}


void test_span() {

    pre_cpp20::use_the_force();
    cpp20_1::use_the_force();
    cpp20_2::use_the_force();

}

std::vector<Droid*> get_suspicious_droids() { return {}; }


bool pre_cpp20::looking_for_these( std::vector<Droid const*> const& droids ) { return false; }
bool cpp20_1::looking_for_these( std::span<Droid const* const> droids ) { return false; }
bool cpp20_2::looking_for_these( std::span<Droid const* const> droids ) { return false; }

// https://peach.sonarsource.com/coding_rules?open=cpp%3AS6188&rule_key=cpp%3AS6188
// https://peach.sonarsource.com/coding_rules?languages=cpp&open=cpp%3AS6231&q=S6231
