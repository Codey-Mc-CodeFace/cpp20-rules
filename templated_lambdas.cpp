#include <utility>

// https://rules.sonarsource.com/cpp/RSPEC-6189

namespace pre_cpp20 {
    void do_something( auto&& arg ) {
        do_something( std::forward<decltype( arg )>( arg ));
    }

    void test() {

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

    void test() {

        auto l = []<typename T>( T&& arg ) {
            do_something( std::forward<T>( arg ));
        };

        l( 42 );

    }
}

// e.g https://peach.sonarsource.com/project/issues?id=c-family%3Aqt&issues=AXpkPW0JtcwyAUBaLg4Y&open=AXpkPW0JtcwyAUBaLg4Y
