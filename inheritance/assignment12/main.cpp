#include <iostream>

class Base {
    int i;
    public:
    Base(int i): i(i) {};
     virtual void print() {
        std::cout<<"Base \n";
    }
};

class Child : public Base {
    public:
    Child(int i): Base(i) {};
    void print() override {
        std::cout<<"Child \n";
    }
};

class GrandChild: public Child {
    public:
    GrandChild(int i): Child(i) {};
    void print() override {
        std::cout<<"Grandchild \n";
    }
};

void print_class(Base &b) {
    b.print();
}

int main(int argc, char const *argv[])
{
    Base b(1);
    Child c(1);
    GrandChild g(1);

    print_class(b);
    print_class(c);
    print_class(g);
    return 0;
}
