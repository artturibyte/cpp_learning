#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


int main() {
    std::string s1{"Hello wordls"};
    std::string search{"wlh"};

    sort(begin(s1), end(s1));
    sort(begin(search), end(search));

    auto res = includes(cbegin(s1), cend(s1), cbegin(search), cend(search));
    
    std::cout<<res<<"\n";
};