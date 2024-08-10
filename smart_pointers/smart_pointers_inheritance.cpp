#include    <memory>
#include    <iostream>
#include    <vector>


class shape {
    public:

    // make shape abstract class by using "empty" pure virtual member function.
    // this means shape does not implement draw, and class cannot be instantiated etc.
    virtual void draw() = 0;
    // Use virtual type, so we can use dynamic member function 
    virtual void whatami() {
        std::cout<<"Basic shape\n";
    }

   virtual ~shape() {
        std::cout<<"deleted shape\n";
    };

};

class circle : public shape {
    public:
    // use override to say that we override base class member function 
    void whatami() override {
        std::cout<<"Circle \n";
    }

    // shapes pure virtual function "draw" must be overrided, 
    // otherwise circle will also be abstract class
    void draw() {};

};

// final: cannot be inherited
class sphere final : public circle {
    public:
    // final: cannot be overrided
    void whatami() override final {
        std::cout<<"Sphere \n";
    }

    ~sphere() {
        std::cout<<"deleted sphere\n";
    };
};


int main(int argc, char const *argv[])
{
    std::vector<std::unique_ptr<shape>> shape_vec;

    shape_vec.push_back(std::make_unique<circle>());
    shape_vec.push_back(std::make_unique<sphere>());

    for (auto &it : shape_vec) {
        it->whatami();
    }


    return 0;
}
