#include    "manual.hpp"

void func(const std::string& str) {
    std::cout<<"\nFunc printing... "<<str<<"\n";

    // compiler cant instantiate here
    print_extern(std::cout, str);
}