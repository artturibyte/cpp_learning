#include    <iostream>
#include    <typeinfo>


class Shape {
    public:
    virtual ~Shape() {};
};

class Triangle : public Shape {};
class Circle : public Shape {};



int main(int argc, char const *argv[])
{
    Circle c;
    Triangle t;
    Shape *pShape = &c;

    if (typeid(*pShape) == typeid(c)) {
        std::cout<<"Type is circle!\n";
    } else {
        std::cout<<"Type did not match!\n";
    }

    std::cout<<typeid(c).name()<<"\n";
    std::cout<<typeid(c).hash_code()<<"\n";
    return 0;
}
