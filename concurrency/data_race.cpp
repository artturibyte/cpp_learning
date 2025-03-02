#include    <iostream>
#include    <thread>
#include    <string>

// Write a function that increments a global int variable 100,000 times in a for loop.
// Write a program that starts concurrent threads which use this as their task function. 
// When all the threads have completed execution, print out the final value of the counter.
// Increase the number of threads until you see anomalous results.

int a = 0;

void increment_a() {
    for (int i = 0; i < 100000; i++)
    {
        a++;
    }
}

int main(int argc, char const *argv[])
{
    std::thread t(increment_a);
    std::thread t2(increment_a);
    std::thread t3(increment_a);

    t.join();
    t2.join();
    t3.join();

    std::cout<<"Value of a: "<<a<<"\n";
    return 0;
}
