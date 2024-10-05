#include    <cassert>
#include    <iostream>

// default value
template <typename T = int>
class Value {
    T val;
    public:
    Value(const T& value): val(value) {};

    void print() {
        std::cout<<"Value: "<< val <<std::endl;
    }
};

int main(int argc, char const *argv[])
{
    int x = 3;
    assert(x == 3);
    Value<> v(4.111);
    Value<double> vd(4.111);
    v.print();
    vd.print();

    return 0;
}
