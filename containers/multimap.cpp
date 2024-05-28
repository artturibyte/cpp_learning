#include    <map>
#include    <string>
#include    "print.cpp"
#include    <vector>
#include    <algorithm>

int main(int argc, char const *argv[])
{
    std::multimap<std::string, int> m1;

    m1.insert({"test", 1});
    m1.insert({"test", 2});
    m1.insert({"a", 2});
    m1.insert({"b", 2});
    print_map(m1);

    auto start = m1.lower_bound("test");
    auto end = m1.upper_bound("test");

    for (auto it = start; it != end; it++)
    {
        if (it->second == 2)
        {
            std::cout<<"Found! Element: "<<it->first<<", Value: "<<it->second<<"\n";
        }
    }

    auto [test_start, test_end] = m1.equal_range("test");

    std::vector<std::pair<std::string, int>> new_vec;
    copy_if(test_start, test_end,  back_inserter(new_vec),[](std::pair<std::string, int> p){return p.second == 2;});

    print_map(new_vec);
    
    return 0;
}
