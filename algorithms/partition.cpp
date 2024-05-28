#include    <algorithm>
#include    <iostream>
#include    <vector>
#include    <string>
#include    "print.cpp"

int main() {
    std::string s{"assdf"};
    std::vector<int> v{1,2,3,5,6,6,7,2,57,2,6};
    std::vector<int> v2;

    std::vector<int> v1{v};

    std::copy(cbegin(v), cend(v), back_inserter(v2));

    std::partition(begin(v), end(v), [](int i){return i% 2 == 0;});

    std::stable_partition(begin(v2), end(v2), [](int i){return i% 2 == 0;});

    //bool b = std::is_partitioned(begin(v2), end(v2), [](int i){return i% 2 == 0;});
    auto point = std::partition_point(cbegin(v2), cend(v2), [](int i){return i% 2 == 0;});

    print(v);
    print(v2);
    
    std::cout<<distance(cbegin(v2), point);
    

}