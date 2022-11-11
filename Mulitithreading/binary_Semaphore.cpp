
// TOPIC: Semaphore In C++

// POINTS:
// 1.0 Semaphore is a signaling mechanism (T1 saying i am done T2 please carry on).
// 2.0 There are two types of semaphores 
//     a. Binary Semaphore
//     b. Counting Semaphore

// BINARY SEMAPHORE:
// 1.0 Binary Semaphore means there are two state 0 or 1.
// 2.0 
#include <mutex>
#include <condition_variable>

#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;
using namespace std::chrono;

class Semaphore {
public:
    Semaphore (int count_ = 0)
    : count(count_) 
    {
    }
    
    inline void notify( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cout << "thread " << tid <<  " notify" << endl;
        //notify the waiting thread
        cv.notify_one();
    }
    inline void wait( int tid ) {
        std::unique_lock<std::mutex> lock(mtx);
        while(count == 0) {
            cout << "thread " << tid << " wait" << endl;
            //wait on the mutex until notify is called
            cv.wait(lock);
            cout << "thread " << tid << " run" << endl;
        }
        count--;
    }
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};
int main()
{
    Semaphore sem(1);
    
    thread s1([&]() {while(true) { this_thread::sleep_for(std::chrono::seconds(5));sem.wait( 1 );}});
    thread s2([&]() {while(true){sem.wait( 2 );}});
    thread s3([&]() {while(true) {this_thread::sleep_for(std::chrono::milliseconds(600));sem.wait( 3 ); }});
    thread s4([&]() {while(true) {this_thread::sleep_for(std::chrono::seconds(5));sem.notify( 4 );}});
    
    
    s1.join();
    s2.join();
    s3.join();
    s4.join();
}