#include <iostream>
#include    <string>

class Person {
    public:    
    int height;
    std::string name;


    Person(int h, std::string n): height(h), name(n) {std::cout<<"Constructing!\n";}

    friend void swap(Person &p1, Person &p2) noexcept;
};

void swap(Person &p1, Person &p2) noexcept {
        std::cout<<"Swapping!\n";
        std::swap(p1.height, p2.height);
        std::swap(p1.name, p2.name);
}

int main(int argc, char const *argv[])
{
    Person p1(1, "asf");
    Person p2(1, "dbdg");
    
    
    std::cout<<"P1 : "<<&p1<<"\n";
    std::swap(p1, p2);

    std::cout<<"P1 : "<<&p1<<"\n";
    std::cout<<"P1 : "<<p1.name<<"\n";
    return 0;
}
