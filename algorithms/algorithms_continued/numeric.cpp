#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

int main() {
    // testing iota & accumulate
    std::vector<int> vec(10);

    std::iota(begin(vec), end(vec), 5);

    int sum = std::accumulate(cbegin(vec), cend(vec), 0);

    int sum_odd = std::accumulate(cbegin(vec), cend(vec), 0,
    [](int sum, int val){return (val % 2 == 0) ? sum + val : sum;});

    std::cout<<sum<<"\n";
    std::cout<<sum_odd<<"\n";
};