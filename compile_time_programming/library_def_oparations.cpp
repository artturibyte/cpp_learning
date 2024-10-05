#include    <functional>
#include    <iostream>


template <typename T, typename Func = std::less<T>>
bool compare(const T& a, const T& b, Func func=Func()) {
    return func(a, b);
}


int main(int argc, char const *argv[])
{
    int a{1}, b{2};
    std::cout << std::boolalpha;
    std::cout<<"\nCompare a & b: "<<compare(a, b);
    std::cout<<"\nCompare a & b: "<<compare(a, b, [](int a, int b){return a > b;});
    std::cout<<std::endl;
    return 0;
}
