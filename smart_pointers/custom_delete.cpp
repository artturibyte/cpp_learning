#include <iostream>
#include <memory>



struct dest {};
struct conn {
    int a = 111;
};

conn connect(dest d) {
    std::cout<< "Connecting!\n";
    conn c;
    return c;
};

void disconnect(conn c) {
    std::cout<<"Disconnecting!\n";
};

void get_data(const dest& d) {
    conn c = connect(d);
   
   /*
   Using custom deleter lambda function, if not used program will crash because no delete exists
   for connection
    */
    auto custom_delete_end_conn = [](conn* c){disconnect(*c);};
    std::unique_ptr<conn, decltype(custom_delete_end_conn)> ptr{&c, custom_delete_end_conn};

    std::cout<<"Got data"<<"\n";
    throw std::invalid_argument( "error" );

};

int main(int argc, char const *argv[])
{
    dest d;

    // deleter is called if exeption is thown
    try
    {
        get_data(d);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
