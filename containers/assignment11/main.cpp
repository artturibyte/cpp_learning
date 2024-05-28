#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>


template<class T>
void print_map(T items) {
    // structured binding, c++17
for (auto [key, element] : items) {
    std::cout<<key<<", "<<element;
    std::cout<<"\n";
}
}


using namespace std;
int main() {

    vector<pair<string, int>> word_vec;
    map<string, int> word_map;
    string s;

    while (getline( cin, s))
    {
      if (s == "") { break;}

      pair<string, int> word{s, s.length()};

      word_vec.push_back(word);
      auto [pos, success] = word_map.insert(word);

      if (success) {
        auto [word, len] = *pos; // iter of word
        std::cout<<"Inserted:"<<word;
      }


    }

    print_map(word_map);

    cout<<"Stopped. \n";
}