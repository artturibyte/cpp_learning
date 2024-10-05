#include    "manual.hpp"

// define template in only one source file
template <typename T>
std::ostream& print(std::ostream& os, const T& t) {
    return os << t;
}

template std::ostream& print(std::ostream& os,const std::string& str);

int main(int argc, char const *argv[])
{
    std::string s{"Hello"};
    std::cout<<"Main printing...\n";
    print(std::cout, s);
    func(s);
    return 0;
}
