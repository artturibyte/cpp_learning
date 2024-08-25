#include    <iostream>
#include    <tuple>
#include    <string>

using namespace std;


tuple<int, string> return_tuple() {
    return {100, "xxyy"};
}

class TestClass
{
private:
    int ii;
    string ss;
    float ff;
public:
    TestClass(int i, string s, float f);
    ~TestClass() = default;
};

TestClass::TestClass(int i, string s, float f): ii(i), ss(s), ff(f)
{
    cout<<ii<<"\n"<<ss<<"\n"<<ff<<"\n";
}


void apply_tuple_to_func(int i, string s, float) {};

int main(int argc, char const *argv[])
{
    // constructor
    tuple<int, string, float> t1{1, "abc", 2.0};

    //c++17, no longer need to declare types. (CTAD, class template argument deduction)
    tuple t1_2{1, "abc", 2.0};

    //make_tuple
    tuple<int, string> t2 = make_tuple(1, "abc");

    // get first element
    get<0>(t2) = 5;

    int a;
    string b;

    // get elements
    tie(a, b) = t2;


    cout<< get<1>(t2) << "\n";
    // get int
    cout<< get<int>(t2) << "\n";

    apply(apply_tuple_to_func, t1_2);

    // return tuple from funct (old method)
    int x;
    string y;
    tie(x, y) = return_tuple();

    // c++17
    auto [x_2, y_2] = return_tuple();

    cout << x << " " << y << "\n";
    cout << x_2 << " " << y_2 << "\n";


    // Construct class , c++17
    TestClass tc = make_from_tuple<TestClass>(t1);
    return 0;
}
