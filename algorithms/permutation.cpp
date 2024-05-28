#include    <algorithm>
#include    <iostream>
#include    <vector>
#include    <string>
#include    "print.cpp"

int main() {
    std::string s{"abc"};
    
    do {
        print(s);
    } while (std::next_permutation(begin(s), end(s)));


}