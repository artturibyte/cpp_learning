#include <iostream>

class vehicle {
    int speed;

    public:
    vehicle(int spd): speed(spd) {
        std::cout<<"vehicle";
    };

    protected:
    void start() {
        std::cout<<"start";
    };
};

class airplane : public vehicle {
    int height;

    public:
    airplane(int speed, int height): vehicle(speed), height(height) {
        std::cout<<"airplane";
    };

    void start() {
        vehicle::start();
        std::cout<<"takeoff";
    };
};

class fighterplane : public airplane {

    public:
    fighterplane(int speed, int height): airplane(speed, height) {
        std::cout<<"fplane";
    };
};


int main(int argc, char const *argv[])
{
    fighterplane ap(100, 1000);

    ap.start();
    return 0;
}
