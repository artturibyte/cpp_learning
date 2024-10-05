#include    "manual.hpp"

int main(int argc, char const *argv[])
{
    std::string s{"Hello"};
    std::cout<<"Main printing...\n";
    print_extern(std::cout, s);
    func(s);
    return 0;
}
