#include    <iostream>
#include    <thread>
#include    <string>
#include    <mutex>
#include    <vector>


std::mutex mut;
std::once_flag of;

class Test
{
private:
    /* data */
public:
    Test(/* args */) {
        std::cout<<"Initializing...\n";
    }
    void func() {};
    ~Test() {

    }
};



Test* ptest = nullptr; // variable will be lazy initialized.

void process() {

    // Double-checked locking. check if class is initialized, if not and check again.
    // Another check is because two threads might be already in this same situation.
    // This can cause datarace before c++17, because "ptest = new Test" can result in
    // situation where pointer is allocated but class is actually not yet initialized. 
    if (!ptest) {
    std::lock_guard<std::mutex> lg(mut);
    if (!ptest)
        ptest = new Test;
    }

    // another option is call_once. This needs global once_flag var.
    //std::call_once(of, []{ptest = new Test;});

    ptest->func(); // test meberfunction call after init.

}

void meyers_singleton_process() {
    // We can also use meyers singleton solution, where we use static local data.
    // With modern c++, static local data is automatically handled only once and the same
    // data is used by multiple threads.
    static Test static_ptest;
    ptest->func();
}

int main(int argc, char const *argv[])
{
    // initialize ptest with 10 threads. Only one init should happen.
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(process));
    }

    // try with singleton method
    for (size_t i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(meyers_singleton_process));
    }

    for (auto &thr : threads)
        thr.join();
    return 0;
}
