#include    <iostream>
#include    <thread>
#include    <string>
#include    <mutex>

std::mutex mut;
using namespace std::literals;

void task() {
    std::string s{"abced"};

    for (size_t i = 0; i < 5; i++)
    {
        try
        {
            // use lockguard instead, when out of scope, unlocked. unique lock can be unlocked in middle.
            //std::lock_guard<std::mutex> lg(mut);
            std::unique_lock<std::mutex> ug(mut);
            //mut.lock();

            std::cout<<s<<"\n";

            // throw exception, unlock not called.
            //throw std::exception();

            // if unique lock can be unlocked, other threads dont need to wait for
            // ... this lock to go out of scope.
            ug.unlock();
            std::this_thread::sleep_for(1s);
            //mut.unlock();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
}

int main(int argc, char const *argv[])
{
    std::thread t1(task);
    std::thread t2(task);
    t1.join();
    t2.join();
    return 0;
}
