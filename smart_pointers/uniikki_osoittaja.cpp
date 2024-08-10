#include    <memory>
#include    <iostream>


void mul_and_print(std::unique_ptr<int> pointer_to_int) {
    std::cout<< *pointer_to_int *2 << "\n";
};

std::unique_ptr<int> return_uniq_point_func() {
    std::unique_ptr<int> uq_i{std::make_unique<int> (99)};

    return uq_i;
};

int main(int argc, char const *argv[])
{
    // make int pointer to heap
    // c++11
    std::unique_ptr<int> p1{new int(42)};

    // c++14 make unique
    auto p2{std::make_unique<int> (42)};

    //operation to pointer object
    //std::cout<< p1.get();
    mul_and_print(std::move(p2));

    std::cout<< *return_uniq_point_func();

    return 0;
}
