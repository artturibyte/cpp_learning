#include    <vector>
#include    <iostream>


void func() {
    std::vector<int>    vecint;
    int i = vecint.at(2);
}
int main(int argc, char const *argv[])
{

    try
    {
        func();
        
    }
    catch(...)
    {
        std::cout << "error!\n";
    }
    
    return 0;
}


