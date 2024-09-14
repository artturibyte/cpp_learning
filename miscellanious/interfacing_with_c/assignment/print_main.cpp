#include    "print.h"
#include    "set"
#include    "vector"
#include    "map"

int main()
{
    // copy content of set to vector and use C program to print the data.
    std::set s{1,2,4,5};
    std::vector<int> v;
    std::vector<int> v_keys;
    std::vector<int> v_values;
    std::map<int, int> my_map{{1,1}, {10,2}, {20,3}};

    for (auto [key, value]: my_map) {
        v_keys.push_back(key);
        v_values.push_back(value);
    }

    std::copy(s.begin(), s.end(), back_inserter(v));
    print_array(v.data(), v.size());
    print_array(v_keys.data(), my_map.size());
    print_array(v_values.data(), my_map.size());
}
