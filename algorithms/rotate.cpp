#include    <algorithm>
#include    <iostream>
#include    <vector>
#include    <string>
#include    "print.cpp"

int main() {
    std::string s{"assdf"};
    std::vector<int> v{1,2,3,5,6};

    std::reverse(begin(s), end(s));

    //std::cout<< s ;

    // size_t v_size{v.size() -1};
    // for (size_t i = 0; i <= v_size / 2; i++)
    // {
    //     std::swap(v[i], v[v_size - i]);
    // }
    // print(v);

    int v_mid = v.size() / 2 -1;
    auto pivot = begin(v);
    std::advance(pivot, v_mid);
    std::rotate(begin(v), pivot, end(v));

    print(v);
    

}