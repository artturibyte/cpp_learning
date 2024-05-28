
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


void print_vec(std::vector<int> v) {


    for (auto i: v) {
        std::cout<<i << ",";
    }
    std::cout<<"\n";
}


int main() {

    std::vector<int> vec1{1,3,5,8,13};

    print_vec(vec1);

    sort(begin(vec1), end(vec1), [] (int i1, int i2) {return i1 > i2;});
    
    print_vec(vec1);
}