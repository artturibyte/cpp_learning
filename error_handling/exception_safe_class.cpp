#include    <iostream>

class String {
    private:
    int size;
    char *data;

    public:
    String(int size): data(new char[size]), size(size) {}

    String(const String &arg): size(arg.size) {
        data = new char[size];
        
        for (int i = 0; i < size; i++)
        {
            data[i] = arg.data[i];
        }
    }

    String& operator =(const String &arg) {
        //copy and swap, strong exception guarantee. (if exception is thrown, previous state returned)
        String temp(arg);
        swap(*this, temp);

        return *this;

        // if (&arg != this)
        // {
        //     char* ndata = new char[arg.size];
        //     delete[] data;
        //     data = ndata;
        //     size = arg.size;
        // }
        // return *this;
    }

    ~String() noexcept {
        delete[] data;
    }

    friend void swap(String &p1, String &p2) noexcept;
};

void swap(String &s1, String &s2) noexcept {
        std::cout<<"Swapping!\n";
        std::swap(s1.size, s2.size);
        std::swap(s1.data, s2.data);
}

int main(int argc, char const *argv[])
{
    String s1{3};
    String s2{5};

    s2 = s1;

    return 0;
}
