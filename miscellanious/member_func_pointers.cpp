#include    <iostream>
#include    <functional>

using namespace std;


class Test
{
    public:
        Test() {};
        
        void print(string s) {
            cout<<"Printed: "<<s<<"\n";
        };
};

int main(int argc, char const *argv[])
{
    // pointer to member function
    auto pfunc = &Test::print;
    Test test;

    (test.*pfunc)("abc1");

    // member function pointer to callable object
    auto f = mem_fn(pfunc);
    f(test, "abc2");

    // bind member function pointer
    auto f2 = bind(&Test::print, &test, placeholders::_1);
    f2("abc3");
    return 0;
}


