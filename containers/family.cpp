#include    <vector>
#include    <iostream>
#include    <string>
#include    <map>

using namespace std;


class family {
    vector<string>  child_names;

    public:

    void add_child(string name) {
        child_names.push_back(name);
    }

    void print_child_names() {
        for (auto name : child_names) {
            cout<<name<<"\n";
        }
    }
};
void print_families(map<string, family> map) {
    for (auto fam : map) {
        cout<<"Family: "<<fam.first<<"\n";
        fam.second.print_child_names();
    }
}


int main(int argc, char const *argv[])
{
    map<string, family> fam_map;
    multimap<string, string>    mm;

    family Simpsons;
    Simpsons.add_child("Bart");
    Simpsons.add_child("Lisa");
    Simpsons.add_child("Maggie");

    fam_map.insert({"Simpsons", Simpsons});

    //print_families(fam_map);

    mm.insert({"Simpsons", "Bart"});
    mm.insert({"Simpsons", "Lisa"});

    for (auto fam : mm) {
        cout<<"Family: "<<fam.first<<" ";
        cout<<"Child: "<<fam.second;
        cout<<"\n";
    }
    
    
    return 0;
}
