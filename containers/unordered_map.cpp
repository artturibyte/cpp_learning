#include    <unordered_map>
#include    <map>
#include    <string>
#include    "print.cpp"

int main(int argc, char const *argv[])
{
    
    std::unordered_map<std::string, int> unordered_m;
    std::map<std::string, int> m;
    unordered_m.insert({"test", 1});
    unordered_m.insert({"test", 1});
    unordered_m.insert({"c", 1});
    unordered_m.insert({"b", 1});
    unordered_m.insert({"x", 1});
    unordered_m.insert({"a", 1});
    print_map(unordered_m);


    unordered_m.erase("test");
    std::cout<<"num of 'test' elements: "<<unordered_m.count("test")<<"\n";

   

    unordered_m.insert({"test", 1});

    auto f = unordered_m.find("test");
    std::cout<<"found 'test' key: "<< f->first <<", num: "<<f->second<<"\n";

    print_map(unordered_m);

    copy(begin(unordered_m), end(unordered_m), std::inserter(m, end(m)));

    std::cout<<"Ordred map:"<<"\n";
    print_map(m);

    return 0;
}
