#include    <iostream>
#include    <thread>
#include    <string>
#include    <mutex>

int a = 0;
std::mutex mutex_lock;
using namespace std::literals;

void increment_a() {
    mutex_lock.lock();
    for (int i = 0; i < 100000; i++)
    {
        a++;
    }
    mutex_lock.unlock();
}

void print() {
    while(!mutex_lock.try_lock()) {
        std::cout<<"Waiting for lock\n";
        std::this_thread::sleep_for(1s);
    }
    std::cout<<"Locked\n"<<a;
    mutex_lock.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread t(increment_a);
    std::thread t2(increment_a);
    std::thread t3(increment_a);
    std::thread t4(print);

    t.join();
    t2.join();
    t3.join();
    t4.join();


    std::cout<<"Value of a: "<<a<<"\n";
    return 0;
}
