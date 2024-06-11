#include    <vector>
#include    <iostream>


void func() {
    try
    {
        std::vector<int>    vecint;
        int i = vecint.at(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        //rethrow
        /*Applications of rethrowing:
        • Logging the details of an error condition at the point where it happens
        • Adding extra information to the exception object
        • Converting the exception object to a higher level type*/
        throw;
    }
    

}
int main(int argc, char const *argv[])
{

    try
    {
        func();
        
    }
    catch(...)
    {
        std::cout << "got error!\n";
    }
    
    return 0;
}


