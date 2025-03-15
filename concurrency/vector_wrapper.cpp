#include    <iostream>
#include    <vector>
#include    <thread>
#include    <mutex>

// wrapper for internally synchronied class

class Vector {
    std::mutex mut;
    std::vector<int> vec;

    public:

    void push_back(const int& i) {
        mut.lock();
        vec.push_back(i);
        mut.unlock();
    }

    void print() {
        // need to be locked, so that vector size is not changed in other thread.
        mut.lock();
        for (int i : vec) {
            std::cout<<i;
        }
        std::cout<<"\n";
        mut.unlock();
    }
};

int main(int argc, char const *argv[])
{
    Vector vec;
    std::thread t1(&Vector::push_back, &vec, 1);
    std::thread t2(&Vector::push_back, &vec, 2);
    
    t2.join();
    t1.join();
    vec.print();
    
    return 0;
}
