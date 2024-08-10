#include    <iostream>
#include    <memory>


int main(int argc, char const *argv[])
{
    std::shared_ptr s_point{std::make_shared<int>(11)};

    std::weak_ptr w_point = s_point;

    s_point = nullptr;

    //Convert the weak_ptr to a shared_ptr, When the original shared_ptr object is still valid
    auto sp = w_point.lock();
    if (sp) {
        std::cout<<*sp<<"\n";
    }
    else {
        std::cout<<"Does not exist\n";
    }
    return 0;
}
