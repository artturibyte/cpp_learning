#include <future>
#include <iostream>
#include <thread>
#include <chrono>


void produce(std::promise<int>& p) {
    try {
        throw std::runtime_error("Something went wrong in producer!");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        p.set_value(42);
    } catch (...) {
        p.set_exception(std::current_exception());
    }
}

void consume(std::future<int>& f) {
    try {
    std::cout << "Waiting for the value..." << std::endl;
    int value = f.get();
    std::cout << "Received value: " << value << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::thread producer(produce, std::ref(p));
    std::thread consumer(consume, std::ref(f));

    producer.join();
    consumer.join();

    return 0;
}