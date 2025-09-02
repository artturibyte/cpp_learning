// two threads waiting others to unlock

#include <thread>
#include <mutex>
#include    <iostream>
#include    <chrono>

using namespace std::literals;

std::mutex mut1;
std::mutex mut2;

// one fix solution would be that both funcs would try to lock mutexes in same order.
// then the deadlock would be avoided. This is not ideal, look also 

void funcA() {
    std::lock_guard<std::mutex> lg(mut1); // aquire lock on lock1
    std::cout<<"thread 1 locked lock1\n";
    std::this_thread::sleep_for(50ms);
    std::cout<<"thread 1 trying to lock lock2...\n";
    std::lock_guard<std::mutex> lg2(mut2);
}

void funcB() {
    std::lock_guard<std::mutex> lg(mut2); // aquire lock on lock1
    std::cout<<"thread 2 locked lock2\n";
    std::this_thread::sleep_for(50ms);
    std::cout<<"thread 2 trying to lock lock1...\n";
    std::lock_guard<std::mutex> lg2(mut1);
}

int main(int argc, char const *argv[])
{
    std::thread thr1(funcA);
    std::thread thr2(funcB);
    thr1.join(), thr2.join();
    return 0;
}
