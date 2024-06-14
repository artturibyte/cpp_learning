//Move constructor and move assignment operator
#include    <iostream>


class MyClass{
};

/*
Add copy and move operators to the following class.
Each operator should print out a message when it is called, to say what kind of operator it is.
*/

class Test {
    private:
    int i{0}; // Built-in member
    MyClass m; // Class member
    public:
    Test() = default; // Constructor (calls m's constructor)

    // Copy constructor
    Test(const Test& arg): i(arg.i), m(arg.m) {
        std::cout<<"\nCalled copy constructor.";
    }

    // Move constructor
    Test(Test&& arg) noexcept : i(arg.i), m(std::move(arg.m)) {
        std::cout<<"\nCalled move constructor.";
    }

    // Copy assignment operator
    Test& operator =(const Test& arg) {
        std::cout<<"\nCalled Copy assignment operator.";
        if (&arg != this) {
            i = arg.i;
            m = arg.m;
        }
        return *this;
    } 

    // Move assignment operator
    Test& operator =(Test&& arg) noexcept {
        std::cout<<"\nCalled Move assignment operator.";
        if (&arg != this) {
            i = arg.i;
            m = std::move(arg.m);
        }
        return *this;
    }
};


int main(int argc, char const *argv[])
{
    Test t1;

    //Test t2 = t1;
    MyClass m;
    Test t3 = Test();
    Test t4(std::move(t1));

    //assignment operator
    t4 = t3;

    //move assignment operator
    t4 = Test();

    std::cout<<std::endl;
    return 0;
}
