#include <iostream>
#include    <chrono>

using namespace std::literals;

int main(int argc, char const *argv[])
{
    std::chrono::seconds i = 2s;
    std::chrono::milliseconds i2{100};
    std::chrono::milliseconds i3{1374};

    std::chrono::milliseconds x = i + i2;

    std::chrono::seconds new_sec = std::chrono::duration_cast<std::chrono::seconds>(i3);


    std::cout<<i.count()<<"\n";
    std::cout<<i2.count()<<"\n";
    std::cout<<x.count()<<"\n";
    std::cout<<new_sec.count()<<"\n";
    return 0;
}
