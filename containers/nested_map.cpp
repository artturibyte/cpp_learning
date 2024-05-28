#include    <map>
#include    <string>
#include    "print.cpp"



int main(int argc, char const *argv[])
{
    using my_map = std::map<std::string, int>;

    my_map m{{"a", 4}, {"b", 3},{"c", 2},{"d", 1}};

    std::map<int, my_map> nested_map;
    nested_map.insert({1, m});
    nested_map.insert({2, m});

    
    for (auto [i, map] : nested_map) {
        std::cout<<"Printing map"<<i<<":\n";
        print_map(map);
    }
    


    return 0;
}
