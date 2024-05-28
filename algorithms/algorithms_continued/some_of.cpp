#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


int main() {
    std::vector<int> v1{1,2,36,5,4,6,5};

    auto even = [](int n){return n % 2 == 0;};
    
    if (std::all_of(cbegin(v1), cend(v1), even)){
        std::cout<<"All even"<<"\n";
    }    

    if (std::any_of(cbegin(v1), cend(v1), even)){
        std::cout<<"Some even"<<"\n";
    } 


};