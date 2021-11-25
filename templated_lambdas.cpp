#include <utility>

// https://rules.sonarsource.com/cpp/RSPEC-6189

namespace pre_cpp20 {
    void do_something( auto&& arg ) {
        do_something( std::forward<decltype( arg )>( arg ));
    }

    void used_in_params() {

        auto l1 = []( auto a1, decltype(a1) a2 ) { /* .. */ };
        auto l2 = []( auto a1, auto a2 ) requires std::same_as<decltype(a1), decltype(a2)> {
            // ...
        };

        l1(0,0);
        l2(0,0);

    }

    void used_in_body() {

        auto l = []( auto&& arg ) {
            do_something( std::forward<decltype( arg )>( arg ));
        };

        l( 42 );

    }
}
namespace cpp20 {
    template<typename T>
    void do_something( T&& arg ) {
        do_something( std::forward<T>( arg ));
    }

    void used_in_params() {

        auto l = []<typename T>( T a1, T a2 ) { /* .. */ };

        l(0,0);

    }

    void used_in_body() {

        auto l = []<typename T>( T&& arg ) {
            do_something( std::forward<T>( arg ));
        };

        l( 42 );

    }
}


// e.g https://peach.sonarsource.com/project/issues?id=c-family%3Aqt&issues=AXpkPW0JtcwyAUBaLg4Y&open=AXpkPW0JtcwyAUBaLg4Y
