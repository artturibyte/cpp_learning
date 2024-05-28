#include    <algorithm>
#include    <iostream>
#include    <vector>
#include    <string>
#include    "print.cpp"

int main() {
    std::string s{"fedcbaghijklmnopqrstu"};
    


    std::partial_sort(begin(s), begin(s) + 5, end(s));

    print(s);


}