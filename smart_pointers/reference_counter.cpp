#include    <iostream>
/*
Modify the constructor, destructor, copy constructor and copy
assignment operator to support reference counting
 */
class String {
    private:
    int size;
    int *counter;
    char *data;

    public:
    String(int size): size(size) {
        counter =new int{0};
        data = new char[size];
        ++*counter;
    }

    String(const String &arg) {
        size = arg.size;
        counter = arg.counter;
        data = arg.data;

        ++*counter;
        std::cout<<"Called copy construction, \n";
    }

    String& operator =(const String &arg) {
        //copy and swap, strong exception guarantee. (if exception is thrown, previous state returned)
        String temp(arg);
        swap(*this, temp);

        return *this;
    }

    ~String() noexcept {
        --*counter;
        if (*counter == 0) {
            delete[] data;
        }
    }

    friend void swap(String &p1, String &p2) noexcept;

    void print() {
        std::cout<<"Data: "<<&data<<", counter: "<<counter<<" "<<*counter<<std::endl;
    }
};

void swap(String &s1, String &s2) noexcept {
        std::cout<<"Swapping!\n";
        std::swap(s1.counter, s2.counter);
        std::swap(s1.size, s2.size);
        std::swap(s1.data, s2.data);
}

int main(int argc, char const *argv[])
{
    String s1{3};
    s1.print();
    String s2{s1};

    s1.print();

    return 0;
}