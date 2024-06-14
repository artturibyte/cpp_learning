#include    <iostream>


class cant_copy {
    int value1;
    public:
    cant_copy(int i): value1(i) {};
    cant_copy(const cant_copy &arg) = delete;
    cant_copy(cant_copy &&arg) noexcept {
        std::cout<<"Move constructor called\n";
        value1 = arg.value1;
    }
    
    void print_val() {
        std::cout<<value1<<"\n";
    }
};

int main(int argc, char const *argv[])
{
    cant_copy cls(2);

    cant_copy cls2 = cant_copy(std::move(cls));

    cls2.print_val();
    //cant_copy cls3 = cant_copy(cls2);

    return 0;
}
