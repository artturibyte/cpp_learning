#include    <iostream>

class Shape {
    public:
    virtual ~Shape() {};
};

class Triangle : public Shape {};
class Circle : public Shape {
    public:
    void func() {
        std::cout<< "Func called\n";
    }
};


int main(int argc, char const *argv[])
{
    Circle c;
    Triangle t;
    
    Shape *pointer_shape = &c;

    Shape& ref_shape = c;

    Circle *pointer_circle = dynamic_cast<Circle *>(pointer_shape);

    if (pointer_circle) {
        pointer_circle->func();
    } else {
        std::cout<<"Could not cast\n";
    }

    try
    {
        // Throws bad cast because shape != triangle
        Triangle& tr = dynamic_cast<Triangle &>(ref_shape);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     

    return 0;


}
