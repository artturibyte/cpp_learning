#include    <iostream>
#include    <string>
#include    <variant>

using namespace std;

enum class TokenType {CHAR, INT, DOUBLE};

union TokenData
{
    char c;
    int i;
    double d;
};

class wrappedUnion
{
private:
    TokenData data;
    TokenType datatype;
public:
    void set_value(char c) {
        data.c = c;
        datatype = TokenType::CHAR;
    }
    void set_value(int i) {
        data.i = i;
        datatype = TokenType::INT;
    }
    void set_value(double d) {
        data.d = d;
        datatype = TokenType::DOUBLE;
    }

    void print() {
        cout<<"data: ";
        if (datatype == TokenType::INT) {
            cout<< data.i;
        }
        if (datatype == TokenType::DOUBLE) {
            cout<< data.d;
        }
        if (datatype == TokenType::CHAR) {
            cout<< data.c;
        }
        cout<<"\n";
    }
};




int main(int argc, char const *argv[])
{
    wrappedUnion t;

    t.set_value('z');
    t.print();

    t.set_value(11);
    t.print();

    t.set_value(12.5);
    t.print();


    // alternative with c++17
    variant<char, int, double> t2;
    t2 = 'z';

    if (holds_alternative<char>(t2)){
        cout<<get<char>(t2);
        cout<<"Char in use!\n";
    }

    return 0;
}

