
//  Read in the data from the attached languages.txt file
//  Use each line of input to populate a language object
//  Add this object to a vector
//  Print out all the data in the vector, separated by commas


#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

struct language {
        std::string lang;
        std::string designer;
        int date;
};

bool is_num(std::string str) {
for (auto ch : str) {
      if(isdigit(ch)) {
        continue;
      }
      else {
        return false;
      }
   }
   return true;
}

int main() {
    std::ifstream infile("languages2.txt");

    if (!infile) {
        std::cout<<"Could not open file\n";
        return -1;
    }
    std::string line;

    std::vector<language> langVec;

    while (getline(infile, line)) {
        std::istringstream is{line};
        language lang;

        int year;
        std::string designer;
        std::string langString;

        std::string word{""};
        is >> langString;

        while (is >> word) {
            if (is_num(word)) {
                year = stoi(word);
            }
            else {
		        designer.append(word);
            }
        }

        lang.lang = langString;
        lang.designer = designer;
        lang.date = year;

        langVec.push_back(lang);
    }
    
    for (language l: langVec) {
        std::cout<<l.lang<<", "<<l.designer<<", "<<l.date<<"\n";
    }
}







