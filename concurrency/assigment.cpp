#include <thread>
#include <iostream>
#include <chrono>

using namespace std::literals;

int x{0};
int calc{0};

void func() {
    while (x == 0) {
        calc++;
        x = 1 - x;
        std::this_thread::sleep_for(50ms);
    }
}

int main()
{
    for (size_t i = 0; i < 10; i++)
    {
    std::thread thr1{ func };
    std::thread thr2{ func };
	
	thr1.join();
	thr2.join();
    x = 0;
    }
    std::cout<<calc;
    

}
