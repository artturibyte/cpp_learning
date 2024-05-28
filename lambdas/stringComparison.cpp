#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


// Case-insensitive string equality. Returns true if lhs and rhs are equal, otherwise false
bool equal_strings(const string& lhs, const string& rhs) {
    return equal(
        cbegin(lhs), cend(lhs), 
        cbegin(rhs), cend(rhs), 
        [] (const char ch1, const char ch2) { return toupper(ch1) == toupper(ch2); }
    );
};


int main(int argc, char const *argv[])
{

    string str1{"abc"};
    string str2{"ABC"};


    if (equal_strings(str1, str2)) {
        cout<<"success\n";
    }
    return 0;
}

