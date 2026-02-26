#include    <condition_variable>
#include    <string>
#include    <chrono>
#include    <thread>
#include    <iostream>

using namespace std::literals;

std::string shared_data;

//mutex for protecting critical section
std::mutex mut;

std::condition_variable cond_var;

//waiting thread
void reader() {
    //lock mutex
    std::unique_lock<std::mutex> ul(mut);
    std::cout<<"Reader locked mutex\n";

    // Calling wait will unlock mutex and makes us wait for
    // condition variable to wake us.
    // (This is done so we dont end up in hot loop.)
    cond_var.wait(ul);
    std::cout<<"Wait ended\n";
    std::cout<<"Data: "<<shared_data;


}


// notifying thread
void writer() {
    {
    std::lock_guard<std::mutex> lg(mut);
    std::cout<<"writer thread locked mutex...\n";
    std::this_thread::sleep_for(2s);
    shared_data = "Hello world!";
    } // unlock

    cond_var.notify_one();

}

int main(int argc, char const *argv[])
{
    std::thread t1(reader);
    std::thread t2(writer);
    t1.join();
    t2.join();
    return 0;
}
