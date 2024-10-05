#include    <string>
#include    <iostream>


template<typename T>
std::string get_string(const T& arg) {
if constexpr (std::is_same<std::string, T>::value) // Replaced by "true" if T is a string, else "false"
    return arg;
else
    return std::to_string(arg);
}

template<int N>
int fibonacci() {
    if constexpr (N > 1)
    {
        return fibonacci<N-1>() + fibonacci<N-2>();
    }
    return N;
    
}

int main(int argc, char const *argv[])
{
    constexpr int x{3};
    get_string(x);

    std::cout<<"Fibonacci of: "<<x<<" is: "<<fibonacci<x>()<<std::endl;
    return 0;
}
