#include    <iostream>
#include    <string>

using namespace std;

enum class TokenType {CHAR, INT, DOUBLE};

union TokenData
{
    char c;
    int i;
    double d;
};

struct taggedUnion
{
    TokenType type;
    TokenData token;
};


int main(int argc, char const *argv[])
{
    taggedUnion t;

    t.type = TokenType::CHAR;
    t.token.c = 'z';

    cout<<t.token.c<<"\n";

    return 0;
}

