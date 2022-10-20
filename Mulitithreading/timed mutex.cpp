// TOPIC: Timed Mutex In C++ Threading (std::timed_mutex)
// We have learned Mutex, Race Condition, Critical Section in previous video.

// NOTES:
// 0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success 
//    otherwise false.
// 1. Member Function:
//    a. lock 
//    b. try_lock
//    c. try_lock_for    ---\ These two functions makes it different from mutex.
//    d. try_lock_until  ---/ 
//    e. unlock


//  EXAMPLE: try_lock_for();
//NOTE:- trylock for wait for some sec if in that time CS is free the it will perform ops otherwise false
//  Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
//  On successful lock acquisition returns true, otherwise returns false.
/*
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int myAmount = 0;
std::timed_mutex m;

void increment(int i) {
	// if(m.try_lock_for(std::chrono::seconds(1))) //1. it will wait for 1 sec if in that time CS is free the it will perform ops otherwise false
	if(m.try_lock_for(std::chrono::seconds(3)))//2. here waiting time is more so t2 will go in CS
	{
		// we are waiting for m.try_lock_for(std::chrono::seconds(2)) for 2 sec there is confisution is will finish or not which one will go first 
		++myAmount;
		std::this_thread::sleep_for (std::chrono::seconds(2)); //since it is sleeping for 2 sec t2 will not go CS return false
		cout << "Thread " << i << " Entered" << endl;
		m.unlock();
	}else{
		cout << "Thread " << i << " Couldn't Enter" << endl;
	}
}

int main() {
	std::thread t1(increment, 1);
	std::thread t2(increment, 2);

	t1.join();
	t2.join();

	cout << myAmount << endl;
	return 0;
}
*/
// Output:- 1. Senerio
// Thread 2 Couldn't Enter
// Thread 1 Entered
// 1

//2. senerio

// Thread 2 Entered
// Thread 1 Entered
// 2





// EXAMPLE: try_lock_until
// Waits until specified timeout_time has been reached or the lock is acquired, whichever comes first.
// On successful lock acquisition returns true, otherwise returns false.

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;


int myAmount = 0;
std::timed_mutex m;

void increment(int i) {
	auto now=std::chrono::steady_clock::now();// from now
//	if(m.try_lock_until(now + std::chrono::seconds(1))) //1. it will wait until 1 sec for CS
	if(m.try_lock_until(now + std::chrono::seconds(3)))//2. here waiting untill 3 sec so t2 will go in CS
	{
		++myAmount;
		std::this_thread::sleep_for (std::chrono::seconds(2));
		cout << "Thread " << i << " Entered" << endl;
		m.unlock();	
	}else{
		cout << "Thread " << i << " Couldn't Enter" << endl;
	}
}

int main() {
	std::thread t1(increment, 1);
	std::thread t2(increment, 2);

	t1.join();
	t2.join();

	cout << myAmount << endl;
	return 0;
}
// Output:- 1. Senerio
// Thread 2 Couldn't Enter
// Thread 1 Entered
// 1

//2. senerio

// Thread 2 Entered
// Thread 1 Entered
// 2


