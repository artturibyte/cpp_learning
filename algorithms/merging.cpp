#include    <algorithm>
#include    <iostream>
#include    <vector>
#include    "print.cpp"

int main() {
    std::vector<int> v{1,2,3,5,4,7,8,6,6};
    std::vector<int> v2{1,2,3,5,4,7,8,6,6};
    
    std::vector<int> v3;

    std::sort(begin(v), end(v));
    std::sort(begin(v2), end(v2));
    std::merge(begin(v), end(v), begin(v2), end(v2), back_inserter(v3));


    print(v3);

    std::vector<int> v4;
    std::set_intersection(begin(v), end(v), begin(v3), end(v3), back_inserter(v4));
    
    print(v4);

    std::vector<int> v5;
    std::set_union(begin(v), end(v), begin(v4), end(v4), back_inserter(v5));
    
    print(v5);

    
}