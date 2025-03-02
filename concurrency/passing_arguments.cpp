#include    <iostream>
#include    <thread>
#include    <string>




void thread_func(std::string &&str) {
    std::cout<<str;
}


void thread_func_reference(std::string &str) {
    std::cout<<str;
}

class Test {
    public:
    void print() {
        std::cout<<"asdfghjk\n";
    }
};

int main(int argc, char const *argv[])
{
    std::string s1{"abcd\n"};
    std::string s2{"abcd\n"};

    Test test;

    // Use callable function with rvalue argument
    std::thread t(thread_func, std::move(s1));
    // Use value by reference
    std::thread t2(thread_func_reference, std::ref(s2));
    // call memberfunction of a object in thread. Pass pointer to function & pointer to object to thread.
    std::thread t3(&Test::print, &test);

    t.join();
    t2.join();
    t3.join();

    return 0;
}
