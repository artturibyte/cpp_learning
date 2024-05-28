#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


int main() {
    std::vector<int> v1{1,2,36,5,4,6,5};

    sort(begin(v1), end(v1));

    auto res = binary_search(cbegin(v1), cend(v1), 7);
    
    std::cout<<res<<"\n";
};