#include    <iostream>
#include    <string>

using namespace std;


union Token
{
    char c;
    int i;
    double d;
};

int main(int argc, char const *argv[])
{
    Token t;

    t.c = 'c';

    cout<<t.c<<"\n";

    return 0;
}

