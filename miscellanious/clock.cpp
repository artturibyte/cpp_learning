#include    <iostream>
#include    <chrono>



long long fibonacci (long long n) {
    return (n < 2 ) ? n: fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char const *argv[])
{
    auto start = std::chrono::steady_clock::now();
    long long n = fibonacci(45);
    std::cout << "Fibonacci number is " << n << std::endl;

    auto finish = std::chrono::steady_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count();
    std::cout<< "Time elapsed: " << elapsed <<" ms\n";
    return 0;
}
