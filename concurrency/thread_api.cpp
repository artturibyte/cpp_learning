#include    <iostream>
#include    <thread>

using namespace std::literals;


void print() {
    std::this_thread::sleep_for(1s);
    std::cout<<"thread slept 1s\n";
}

int main(int argc, char const *argv[])
{
    

    std::this_thread::sleep_for(1s);
    std::cout<<"slept for 1s\n";
    std::thread t(print);

    std::cout<<"Main thread id: " << std::this_thread::get_id() << "\n";
    std::cout<<"Second thread id: " << t.get_id() << "\n";

    t.join();
    return 0;
}
