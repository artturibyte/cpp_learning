#include <mutex>
#include <future>
#include <iostream>

class some_type {
	// ...
public:
	void do_it() { std::cout << "Doing it!" << std::endl; }
};

std::atomic<some_type *> ptr{nullptr};            // Variable to be lazily initialized
std::mutex process_mutex;

void process() {
    if (!ptr) {                     // First check of ptr
        std::lock_guard<std::mutex> lk(process_mutex);
        
        if (!ptr.load(std::memory_order_relaxed))                  // Second check of ptr
            ptr.store(new some_type, std::memory_order_release);   // Initialize ptr
    }
    some_type *p = ptr;
    p->do_it();
}

int main() {
    process();
}