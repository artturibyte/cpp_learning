#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include    <random>

int main() {

    // OLD C++

    // Seed
    std::srand(time(0));
    for (size_t i = 0; i < 2; i++)
    {
        // Random int
        std::cout<<rand()<<"\n";
    }

    // Modern C++

    std::random_device rand_d;

    std::default_random_engine eng1(rand_d());
    std::mt19937 eng2(rand_d());

    std::uniform_int_distribution<int> idist(1, 10);
    std::uniform_real_distribution<float> fdist(1, 10);

    for (size_t i = 0; i < 2; i++)
    {
        // Random int
        std::cout<<"Int rand: "<<idist(eng1)<<"\n";
        std::cout<<"Float rand: "<<fdist(eng2)<<"\n";
    }

    
}