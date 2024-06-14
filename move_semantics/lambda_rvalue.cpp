#include    <iostream>
#include    <string>


int main(int argc, char const *argv[])
{
    std::string x{"abc"};

    std::cout<<x<<"\n";
    [rval_x = std::move(x)](){std::cout<<"X in lambda: "<<rval_x<<"\n";}();
    std::cout<<"X after move: "<<x<<"\n";
    return 0;
}
