#include    "manual.hpp"

void func(const std::string& str) {
    std::cout<<"\nFunc printing... "<<str<<"\n";

    // compiler cant instantiate here
    print(std::cout, str);
}