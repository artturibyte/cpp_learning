#include    <vector>
#include    <iostream>


class problem {
    public:
    problem() {
        throw std::logic_error("asd");
    }
};


int main(int argc, char const *argv[])
{

    try
    {
        problem p;
    }
    catch(std::exception &e)
    {
        std::cout << "got error!\n";
        std::cout<< e.what();
    }
    
    return 0;
}


