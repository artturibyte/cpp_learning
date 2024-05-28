
#include <iostream>
#include "grid.h"


int main() {
    std::cout<<"Conway's game of Life\n";
    std::cout<<"Press return key to display each rotation\n";

    //Wait for user to press the return key
    std::cin.get();

    //Grid for the first gen
    grid current_gen;

    current_gen.randomize();

    while (true) {
        current_gen.draw();

        //wait for keypress
        std::cin.get();

        //grid for next gen
        grid next_gen;

        //populate cells in next
        calculate(current_gen, next_gen);

        current_gen.update(next_gen);
    }
}