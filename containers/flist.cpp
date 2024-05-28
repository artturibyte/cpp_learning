#include    <iostream>
#include    <forward_list>


int main(   ){
    std::forward_list<int> fl{1,2, 3, 4};

    for (auto i : fl) {
        std::cout<<i<<",";
    }
    std::cout<<"\n";

    int mid = distance(begin(fl), end(fl)) / 2;
    auto middle = begin(fl);
    advance(middle, mid);

    fl.insert_after(middle, 666);

        for (auto i : fl) {
        std::cout<<i<<",";
    }
    std::cout<<"\n";

    fl.erase_after(middle);

    for (auto i : fl) {
        std::cout<<i<<",";
    }
    std::cout<<"\n";
}