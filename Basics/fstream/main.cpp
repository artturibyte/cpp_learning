#include <iostream>
#include <fstream>

int main( ) {
    int x;

    std::cin>>x;

    bool success{false};
    while (!success) {

        if (std::cin.good()) {
            std::cout<<"Success\n";
            success = true;
            }
        
        if (std::cin.fail()) {
            std::cout<<"Try again\n";
            std::cin.clear();
            std::cin.ignore(20, '\n');
            std::cin >> x;
            }

    }

}