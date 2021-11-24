cmake_minimum_required(VERSION 3.20)
project(cpp20_rules)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp20_rules main.cpp spaceship.cpp enable_if.cpp no_unique_address.cpp templated_lambdas.cpp bit_cast.cpp pf_bit.h pf_concepts.h span.cpp starts_with.cpp contains.cpp erase.cpp midpoint.cpp)
