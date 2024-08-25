#include    <bitset>
#include    <iostream>


int main(int argc, char const *argv[])
{
    std::bitset<8>  b1{"11110000"};
    std::bitset<8>  b2{10};
    std::bitset<8>  b3{0x8};

    std::cout<< b1 << std::endl;
    std::cout<< b2 << std::endl;
    std::cout<< b3 << std::endl;

    // try to access bit
    try
    {
        std::cout<< b3.test(8) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<< b3 << std::endl;

    //left shift
    std::cout<< (b1 << 2) << std::endl;
    //right shift
    std::cout<< (b1 >> 2) << std::endl;

    //invert bits
    b1.flip();
    std::cout<< b1 << std::endl;

    //set to false
    b1.reset();
    std::cout<< b1 << std::endl;

    //set to true
    b1.set();
    std::cout<< b1 << std::endl;

    std::cout<< b1.all() << std::endl;
    std::cout<< b1.any() << std::endl;
    std::cout<< b1.count() << std::endl;

    return 0;
}
