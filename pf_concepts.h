#ifndef CPP20_RULES_PF_CONCEPTS_H
#define CPP20_RULES_PF_CONCEPTS_H

#include <concepts>

namespace std {
    template<class T>
    concept signed_integral = std::is_integral_v<T> && std::is_signed_v<T>;
}

#endif //CPP20_RULES_PF_CONCEPTS_H
