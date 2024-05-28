#include    <algorithm>
#include    <iostream>
#include    <vector>


int main() {
    std::vector<int> v{1,2,3,5,4,7,8,6,6};

    std::vector<int> v2(v.size());
    std::vector<int> v3;
    std::vector<int> v4;
    std::vector<int> v5;

    std::copy(cbegin(v), cend(v), begin(v2));
    std::copy_n(cbegin(v), 2, back_inserter(v3));
    std::copy_if(cbegin(v), cend(v), back_inserter(v4), [](int i){return i % 2 == 0; });


    std::replace(begin(v), end(v), 6, 7);
    for (auto i : v) {
        std::cout<<i<<", ";
    }
    std::cout<<"\n";

    auto pos = std::remove(begin(v), end(v), 7);
    v.erase(pos, end(v));
    std::remove_if(begin(v), end(v), [](int i){ return i % 2 == 0;});
    for (auto i : v) {
        std::cout<<i<<", ";
    }
    std::cout<<"\n";

    std::remove_copy(begin(v), end(v), back_inserter(v5), 5);
    for (auto i : v5) {
        std::cout<<i<<", ";
    }
    std::cout<<"\n";

    auto pos_u = std::unique(begin(v), end(v));
    v.erase(pos_u, end(v));
    for (auto i : v) {
        std::cout<<i<<", ";
    }
    std::cout<<"\n";
}