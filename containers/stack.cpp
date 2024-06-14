#include    <stack>
#include    <iostream>


int main(int argc, char const *argv[])
{
    std::stack<int> stck1;

    stck1.push(1);
    stck1.push(11);
    stck1.push(111);
    stck1.push(1213);
    stck1.push(123);
    stck1.push(133);

    std::cout<<stck1.top();
    std::cout<<"\n";
    std::cout<<stck1.empty();
    std::cout<<"\n";
    std::cout<<stck1.size();
    std::cout<<"\n";

    stck1.pop();

    std::cout<<stck1.top();
    std::cout<<"\n";
    std::cout<<stck1.empty();
    std::cout<<"\n";
    std::cout<<stck1.size();
    std::cout<<"\n";


    return 0;
}
