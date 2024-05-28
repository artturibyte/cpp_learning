#include    <iostream>
#include    <list>


void print_list(std::list<int> l) {
        for (auto i : l) {
        std::cout<<i<<",";
    }
    std::cout<<"\n";
}

int main(){
    std::list<int> l{1,3, 12, 4, 5, 5, 8, 9, 5, 1, 2, 3};
    std::list<int> l2{1,3, 12, 4, 5};


    int mid = distance(begin(l), end(l)) / 2;
    auto middle = begin(l);
    advance(middle, mid);
    print_list(l);

    l.insert(middle, 666);

    advance(middle, -1);
    l.erase(middle);

    print_list(l);

    l.sort();

    print_list(l);

    l2.sort();
    l.merge(l2);

    print_list(l);

}