#include    <iostream>
#include    <vector>


// return sum of two any arguments. with c++11 you need to declare type. 
// deduced return type available with ‘-std=c++14’
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main(int argc, char const *argv[])
{
    const int x{99};
    auto a = x;
    decltype(x) b = x;

    // make vector lambda c++14 -->
    //auto generic_lambda = [](auto x, size_t n) {return std::vector<decltype(x)>(n, x);};

    a++;
    //b++;  //error, b = const

    //std::vector<int> v = generic_lambda(2, 3);

    std::cout<< add(3 , 5);

    std::cout<<"auto a: "<<a<<"\n";
    std::cout<<"decltype(x) b: "<<b<<"\n";
    
    return 0;
}
