#include    <iostream>
#include    <thread>
#include    <string>

void thread_func(std::string &&str) {
    std::cout<<str;
}



int main(int argc, char const *argv[])
{
    std::string s1{"abcd\n"};
    std::string s2{"abcd\n"};
    std::string s3{"abcd\n"};

    // Use callable function with rvalue argument
    std::thread t(thread_func, std::move(s1));
    std::thread t2(thread_func, std::move(s2));
    std::thread t3(thread_func, std::move(s3));

    t.join();
    t2.join();
    t3.join();

    return 0;
}
