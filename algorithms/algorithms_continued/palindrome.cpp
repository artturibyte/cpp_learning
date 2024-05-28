#include    <string>
#include    <iostream>
#include    <algorithm>


std::string normalise_string(std::string s) {
    // remove all but chars
    auto defunct = std::remove_if(begin(s), end(s), [](char c){return !(isalpha(c));});
    s.erase(defunct, end(s));

    // to lowercase
    std::transform(begin(s), end(s), begin(s),  [](char c){return tolower(c);});

    return s;
}

int main() {
    std::string s1;

    std::cout<<"Give word to check for palindrome: \n";
    std::cin>>s1;

    std::string s2 = normalise_string(s1);


    auto iters = std::mismatch(cbegin(s2), cend(s2), crbegin(s2));

    if (iters.first != cend(s2)) {
        std::cout<<"Diff with: \n";
        std::cout<<*iters.first<<"\n";
        std::cout<<*iters.second<<"\n";
    } else {
        std::cout<<"Found palindrome!";
        std::cout<<"\n";
    }


    
}