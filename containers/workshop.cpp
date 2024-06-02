#include    <iostream>
#include    <string>
#include    <vector>
#include    <list>
#include    <deque>
#include    <map>
#include    <set>


template<class T>
void print_map(T items) {
    // structured binding, c++17
for (auto [key, element] : items) {
    std::cout<<key<<", "<<element;
    std::cout<<"\n";
}
}

template<class T>
void print_vec(T items) {
    // structured binding, c++17
for (auto element : items) {
    std::cout<<element;
    std::cout<<"\n";
}
}


using namespace std;
int main() {

    
    //vector<string> word_vec;
    //list<string> word_vec;
    //deque<string> word_vec;
    
    set<string> word_vec;
    string s;

    while (getline( cin, s))
    {
      if (s == "") { break;}


      word_vec.insert(s);

    }

    print_vec(word_vec);

    cout<<"Stopped. \n";
}