#include    <iostream>
#include    <vector>
#include    <string>
#include    <list>
#include    <deque>

using namespace std;
int main() {
    string s;
    vector<string> s_vec;
    list<string> s_list;
    deque<string> s_deque;
    while (getline( cin, s ))
    {
      if (s == "") { break;}

      s_vec.push_back(s);
      //s_list.push_back(s);
      s_list.push_front(s);
      //s_deque.push_back(s);
      s_deque.push_front(s);
    }

    for (auto s: s_list) { cout<<s<<","; }
    
    cout<<endl;
    cout<<"Stopped. \n";
}