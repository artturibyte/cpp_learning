
// simulation of download program, where one thread is fetching data and other is displaying
//progress bar. After success, process_data thread has waited for finish and processes data.
// see better solution with "condition variables".

#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <chrono>
#include <condition_variable>


using namespace std::literals;


// shared variable for fetched data
std::string sdata;

bool update_progress = false;
bool completed = false;

std::mutex data_mutex;
std::mutex completed_mutex;

std::condition_variable data_cv;
std::condition_variable completed_cv;

void fetch_data() {
    for (int i = 0; i < 5; i++)
    {
        std::cout<<"Fetcher thread waiting for data..."<<std::endl;
        std::this_thread::sleep_for(2s);

        // updata data, then notify progress bar thread
        std::lock_guard<std::mutex> data_lock(data_mutex);
        sdata += "Block" + std::to_string(i+1);
        std::cout<< "sdata: " << sdata << std::endl;
        update_progress = true;
        data_cv.notify_all();
    }

    std::cout<<"Fetch data has ended\n";

    //tell the progressbar to exit and wake up processing thread
    std::lock_guard<std::mutex> completed_lck(completed_mutex);
    completed = true;
    completed_cv.notify_all();
    
}

void progress_bar() {
    size_t len = 0;

    while (true)
    {
        std::cout<<"Progress bar thread waiting for data..." << std::endl;

        // wait for new data
        std::unique_lock<std::mutex> data_lock(data_mutex);
        
        data_cv.wait(data_lock, []{return update_progress;});

        len = sdata.size();

        update_progress = false;
        data_lock.unlock();

        std::cout<<"Received: " << len << " bytes so far" << std::endl;

        // terminate after load has finished
        std::unique_lock<std::mutex> completed_lck(completed_mutex);
        if (completed_cv.wait_for(completed_lck, 10ms, []{return completed;})){
            std::cout << "Progress bar has ended...\n";
            break;
        }
    }
}

void process_data() {
    std::cout<<"Processing thread waiting for data"<< std::endl;

    // wait until download is completed
    std::unique_lock<std::mutex> completed_lck(completed_mutex); // ackquire lock
    completed_cv.wait(completed_lck, []{return completed;});
    completed_lck.unlock();
    
    std::lock_guard<std::mutex> data_lck(data_mutex);
    std::cout<<"Processing sdata"<< sdata << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread fetcher(fetch_data);
    std::thread prog(progress_bar);
    std::thread process(process_data);

    fetcher.join();
    prog.join();
    process.join();

    return 0;
}
