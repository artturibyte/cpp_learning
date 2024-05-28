#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


auto string_in_lamda_out(const std::string& s) {
    return [s] (const std::string& str) {std::cout<<s<<str<<"\n"; };
}


int main() {
    std::vector<std::string> words{"abc","def", "sfdghsd"};
    int n{5}, idx{0};

    auto lambda_find = [&] (const std::string& str) { ++idx; return str.size() > n; };
    auto res = find_if(cbegin(words), cend(words), lambda_find);

    auto l = string_in_lamda_out("abc");
    l("123");
    

}
