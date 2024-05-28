#include    <iostream>


template<class T>
void print_map(T items) {
for (auto item : items) {
    std::cout<<item.first<<", "<<item.second;
    std::cout<<"\n";
}
}

template<class T>
void print_vec(T items) {
for (auto item : items) {
    std::cout<<item<<", ";
    std::cout<<"\n";
}
}