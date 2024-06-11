#include    <vector>
#include    <iostream>

int main(int argc, char const *argv[])
{

    std::vector<int>    vecint;

    //int i = vecint[2];
    //int i = vecint.at(2);
    try
    {
        //int i = vecint[2];
        //vecint.at(2);
        try
        {
            vecint.at(2);
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << "error!\n";
            std::cerr << e.what() << '\n';
        }
        
    }
    catch(const std::exception& e)
    {
        std::cout << "nested error!\n";
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}


