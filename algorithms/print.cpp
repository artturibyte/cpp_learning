#include    <iostream>


template<class T>
void print(T stuff) {
    for (auto i : stuff) {
        std::cout<<i<<", ";
    }
    std::cout<<"\n";
}