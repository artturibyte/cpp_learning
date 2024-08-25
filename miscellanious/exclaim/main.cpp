#include <iostream>
#include <string>

std::string exclaim(std::string string) {
    //The function will return the argument string, 
    //but with all the punctuation characters replaced by an exclamation mark.

    for (auto& ch: string)  {
        if (ispunct(ch)) {
            //std::cout<<"Is punct"<<ch<<"\n";
            ch = '!';
        }
    }
    return string;
}

int main() {
    std::string s1{"To be, or not to be, that is the question:"};
    std::string s2 = exclaim(s1);

    std::cout<<s1<<"\n";
    std::cout<<s2<<"\n";
}