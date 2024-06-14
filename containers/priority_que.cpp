#include    <queue>
#include    <iostream>


int main(int argc, char const *argv[])
{
    std::priority_queue<int> q1;

    q1.push(1);
    q1.push(11);
    q1.push(111);
    q1.push(1213);
    q1.push(123);
    q1.push(133);

    std::cout<<q1.top();
    std::cout<<"\n";
    std::cout<<q1.empty();
    std::cout<<"\n";
    std::cout<<q1.size();
    std::cout<<"\n";

    q1.pop();

    std::cout<<q1.top();
    std::cout<<"\n";
    std::cout<<q1.empty();
    std::cout<<"\n";
    std::cout<<q1.size();
    std::cout<<"\n";


    return 0;
}
