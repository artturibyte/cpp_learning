#include    <iostream>
#include    <array>


void print_array(std::array<int, 5> ar) {
    for (auto i: ar) {
        std::cout<<i<<"\n";
    }
}

void print_array(int *array, int n) {
    for (size_t i = 0; i < n; i++)
    {
        std::cout<<array[i]<<"\n";
    }
    
}


int main() {
    std::array<int, 5> ar1{1 ,2, 4, 5, 6};

    ar1[1] = 66;

    int old_array[] = {1, 2, 3, 5, 6};
    int n = sizeof(old_array) / sizeof(old_array[0]);

    //print_array(ar1);
    print_array(old_array, n);
}