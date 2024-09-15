#include    <iostream>

struct [[nodiscard]] test
{
    /* data */
};


[[deprecated("use 2.0 version instead")]][[noreturn]] void func() {
    std::cout<< "No return func"<<std::endl;
    while (true)
    {
        /* code */
    }
}


[[nodiscard]] int calc() {
    return 1;
}

test return_struct() {
    test t;
    return t;
}

int main(int argc, char const *argv[])
{
    // if compiler warns unused variable
    [[maybe_unused]] char buffer[128];
    int xyz = 1;
    //func();
    int x = calc();
    test t = return_struct();

    switch (xyz)
    {
    case 0:
        std::cout<<"Case0 \n";
        // [[fallthrough]]  // if compiler warns about fallthrough
    case 1:
        
        std::cout<<"Case1 \n";
        
    case 2:
        std::cout<<"Case2 \n";
    default:
        break;
    }
    return 0;
}
