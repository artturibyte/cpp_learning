#include    <iostream>
#include    <thread>
#include    <string>
#include    <shared_mutex>
#include    <vector>
#include    <chrono>

int x = 0;
std::shared_mutex s_mut;

/*
In this example, we have situation where reading the data can be done concurrently,
but writing needs to be locked. Situation where there is lot of reads, but rarely write to data,
we can use shared mutex & shared lock and lock_guard. Multiple threads can set shared lock 
and this does lock other threads until lock_guard is set.
Note that shared_mutex is little more expensive than normal mutex.
*/

void write() {
    std::lock_guard<std::shared_mutex> lm(s_mut);
    x++;
}

void read() {
    // sleep is set to simulate time for reading some data. If shared lock is not used,
    // this operation needs to be done separately with every thread.
    // Lock needs to be used because cannot read data while writing.
    //std::lock_guard<std::shared_mutex> lm(s_mut);
    std::shared_lock<std::shared_mutex> lm(s_mut);
    using namespace std::literals;
    std::this_thread::sleep_for(1s);
}

int main(int argc, char const *argv[])
{
    

std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    std::vector<std::thread> threads;
    for (size_t i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(read));
    }

    threads.push_back(std::thread(write));
    threads.push_back(std::thread(write));

    for (size_t i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(read));
    }

    for (auto &thr : threads)
        thr.join();
    
    std::cout<<x<<"\n";

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "ms" << std::endl;
    return 0;
}
