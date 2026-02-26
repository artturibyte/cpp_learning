#include <iostream>
#include <thread>
#include <condition_variable>
#include <string>

using namespace std;
using namespace std::chrono;

// Global variables
mutex complete_mutex;
mutex data_mutex;
bool data_processed = false;
string sdata{"Empty"};

// Waiting thread
void reader() {
    std::unique_lock<std::mutex> uq_lock(complete_mutex);
    while (!data_processed) {
        uq_lock.unlock();
        std::cout<<"waiting complete lock...\n";
        std::this_thread::sleep_for(500ms);
        uq_lock.lock();
    }

	lock_guard<std::mutex> guard(data_mutex); // Acquire lock
    cout << "Data is " << sdata << endl;           
}

// Modyifing thread
void writer() {
	cout << "Writing data..." << endl;
	{
		lock_guard<std::mutex> lg(data_mutex);            // Acquire lock
		std::this_thread::sleep_for(2s);           // Pretend to be busy...
		sdata = "Populated";                       // Modify the data
	}

    std::lock_guard<std::mutex> completed_lck(complete_mutex);
    data_processed = true;
}

int main() {
	cout << "Data is " << sdata << endl;
	thread read{reader};
    thread write{writer};
	
	write.join();
	read.join();
}