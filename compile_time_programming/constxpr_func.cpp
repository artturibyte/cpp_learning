#include    <iostream>



constexpr double miles_to_km(double miles) {
    return miles * 1.602;
}


int main(int argc, char const *argv[])
{
    double d{20};
    // can be used with non const expression values
    // in this case function is evaluated in run-timr
    double value = miles_to_km(d);
    std::cout<<miles_to_km(10);
    return 0;
}
