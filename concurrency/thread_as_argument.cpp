#include    <iostream>
#include    <thread>

void print() {
    std::cout<<"hello\n";
}

void thread_as_argument(std::thread t) {
    std::cout<< "received thread with id: " <<  t.get_id() <<"\n";
    // function now responsible for thread
    t.join();
}

std::thread return_thread() {
    // start thread
    std::thread t(print);
    return t;
}

int main(int argc, char const *argv[])
{
    std::thread t(print);
    std::cout<< "thread id: " <<  t.get_id() <<"\n";

    // thread can be only moved
    thread_as_argument(std::move(t));

    std::thread t2 = return_thread();
    t2.join();
    return 0;
}
