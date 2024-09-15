#include    <iostream>

class Hardware_device
{
private:
    /* data */
public:
    Hardware_device(/* args */);
    ~Hardware_device() = default;
};

class Touch_responder
{
private:
    /* data */
public:
    Touch_responder(/* args */);
    ~Touch_responder() = default;
};

class Mouse: public Hardware_device, Touch_responder
{
private:
    /* data */
public:
    Mouse(/* args */) = default;
    ~Mouse() = default;
};




Touch_responder::Touch_responder(/* args */)
{
    std::cout<<"Construct touch interface\n";
}

Hardware_device::Hardware_device(/* args */)
{
    std::cout<<"Construct hw device\n";
}

int main(int argc, char const *argv[])
{
    Mouse mouse;
    return 0;
}
