#include    <iostream>

void print_rvalue(int&& i) {
    std::cout<<"rvalue: "<< i << ", reference: "<< &i << "\n";
}

int main(int argc, char const *argv[])
{
    //lvalue refernce:
    int i{455};
    int *ref_i = &i;
    std::cout<<"lvalue: "<< &i << ", reference: "<< ref_i << "\n";

    //rvalue refernce:
    const int &rref_i = 3;
    std::cout<<"rvalue: "<< rref_i << ", reference: "<< &rref_i << "\n";
    print_rvalue(3);
    print_rvalue(3);
    print_rvalue(3);

    return 0;
}
