
#include <fstream>
#include <string>
#include <iostream>

void read_from_file(const std::string &str) {

    std::ifstream ifile(str);
    if (ifile) {
        std::string text{""};
        while (std::getline(ifile, text)) {
            std::cout << text << "\n";
        }
    }
    ifile.close();
}

void write_to_file(const std::string &str, const std::string &text) {
    std::ofstream ofile(str);
    if (ofile) {
        ofile << text ;
    }
    ofile.close();
}

int main() {
    std::string fileName{"test.txt"};

    read_from_file(fileName);
    write_to_file(fileName, fileName);

} 