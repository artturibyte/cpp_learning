#include    <functional>
#include    <string>
#include    <iostream>
#include    <vector>

using namespace std;

bool match(string animal, string species) {
    return animal == species;
}

int main(int argc, char const *argv[])
{
    vector<string> animals{"cat", "dog", "cat", "moose"};

    auto bind_match = bind(match, placeholders::_1, "cat");
    // equilavent as lambda:
    auto match_cat = [species = "cat"](string animal) {return match(animal, species);};
    //lamdas are kind of better...
    if (bind_match("cat")){
        cout<<"Cat found!\n";
    }
    cout<<count_if(begin(animals), end(animals), bind_match)<< " : Cats found\n";
    return 0;
}
