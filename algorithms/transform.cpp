#include    <algorithm>
#include    <iostream>
#include    <vector>
#include    <string>



bool equal_string(std::string s1, std::string s2) {
    std::transform(cbegin(s1), cend(s1), begin(s1), ::toupper);
    std::transform(cbegin(s2), cend(s2), begin(s2), ::toupper);

    return s1 == s2;

}

int main() {
    std::vector<int> v{1,2,3,5,4,7,8,6,6};
    std::vector<int> v2;
    std::vector<int> v3;

    // triple v to v2
    std::transform(cbegin(v), cend(v), back_inserter(v2), [](int i){return i * 3;});

    // triple v
    std::transform(cbegin(v), cend(v), begin(v), [](int i){return i * 3;});

    // v + v2 to v3
    std::transform(cbegin(v), cend(v), begin(v2), back_inserter(v3), [](int i1, int i2){return i1 + i2;});

    for (auto i : v) {
        std::cout<<i<<", ";
    }
    std::cout<<"\n";

    for (auto i : v3) {
        std::cout<<i<<", ";
    }

    std::string s1{"AAAb"};
    std::string s2{"aaaB"};

    std::cout<<"Is equal: "<< equal_string(s1, s2);
    std::cout<<"\n";
    std::cout<<s1;
    std::cout<<"\n";
    std::cout<<s2;


}