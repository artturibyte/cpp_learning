#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


int main() {
    std::string s1{"sfgaglfgakgf"};

    std::vector<int> v1{1,2,36,5,4,6,5};
    std::vector<int> v2{1,2,36,5,4,7,5};

    auto iters = std::mismatch(cbegin(v1), cend(v1), cbegin(v2), cend(v2));

    if (iters.first != cend(v1) && iters.second != cend(v2)) {
        std::cout<<*iters.first<<"\n";
        std::cout<<*iters.second<<"\n";
    }

};