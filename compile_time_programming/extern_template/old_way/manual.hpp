#pragma once
#include    <iostream>
#include    <string>


// template declaration
template <typename T>
std::ostream& print(std::ostream& os, const T& t);

// template declaration extern
template <typename T>
std::ostream& print_extern(std::ostream& os, const T& t) {
    return os << t;
}

extern template std::ostream& print_extern(std::ostream& os, const std::string& str);

void func(const std::string& str);