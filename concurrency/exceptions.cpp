#include    <iostream>
#include    <thread>
#include    <string>


void thread_func() {
    std::cout<<"test\n";
}

// Solution2 (see solution1 in main) : RAII. create a wrapper for the thread object and call join in the destructor.
// no need to call join in two separate places
class thread_wrapper
{
private:
    std::thread thr;
public:
    // thread is move only
    explicit thread_wrapper(std::thread &&thread): thr(std::move(thread)) {

    }
    thread_wrapper(const thread_wrapper&) = delete;
    thread_wrapper operator=(const thread_wrapper&) = delete;

    ~thread_wrapper() {
        if (thr.joinable()) {
            thr.join();
        }
    }
};



// how to handle threads in the case of exceptions
int main(int argc, char const *argv[])
{
    // init thread outside of try
    std::thread t(thread_func);

    thread_wrapper tw(std::move(std::thread(thread_func)));

    // option 1: join both in try & catch block.
    try
    {
        //throw std::exception();

        // if no exeption and code would continue normally
        t.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        // join thread if exeption. need to be handled before killing program.
        t.join();
    }
    

    return 0;
}
