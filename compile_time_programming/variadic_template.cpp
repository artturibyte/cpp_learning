#include    <iostream>
#include    <tuple>

template <typename T>
void func(T t) {
    std::cout<<"Argument: "<< t <<"\n";
}

template <typename T, typename... Args>
void func(T t,Args... args) {
    std::cout<<"Size: "<<sizeof...(args)<<"\n";
    std::cout<<"Argument: "<< t <<"\n";
    func(args...);
}

int main(int argc, char const *argv[])
{
    func(1, "abc");
    return 0;
}
