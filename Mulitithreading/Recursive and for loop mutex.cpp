// TOPIC: Recursive Mutex In C++ (std::recursive_mutex)
 
// NOTES:
// 0. It is same as mutex but, Same thread can lock one mutex multiple times using recursive_mutex.
// 1. If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1, now 
//    as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue.
// 2. But if T1 have aquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock
//    it 10 times otherwise no other thread will be able to lock mutex m1.
//    It means recursive_mutex keeps count how many times it was locked so that many times it should be unlocked.
// 3. How many time we can lock recursive_mutex is not defined but when that number reaches and if we were calling
//    lock() it will return std::system_error OR if we were calling try_lock() then it will return false.

// BOTTOM LINE:
// 0. It is similar to mutex but have extra facitility that it can be locked multiple time by same thread.
// 1. If we can avoid recursive_mutex then we should becuase it brings overhead to the system.
//2. It can be used in loops also.;
/*
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


// EXAMPLE 1: With Recursion 

std::recursive_mutex m1;
int buffer = 0;
int full =0;

void recursion(char c, int loopFor) {

	if(loopFor<0)
		return;

	m1.lock();
	cout << "Locked By ThreadID:" << c << " " << buffer++ << endl;
	full=buffer; 
	recursion(c, --loopFor);
	m1.unlock();
	cout << "Unlocked By ThreadID:" << c <<" "<<--full<< endl; 
}

int main() {
	thread t1(recursion, '1', 5);
	thread t2(recursion, '2', 5);
	t1.join();
	t2.join();
	return 0;
}
*/

/*
Output :-
Locked By ThreadID:2 0
Locked By ThreadID:2 1
Locked By ThreadID:2 2
Locked By ThreadID:2 3
Locked By ThreadID:2 4
Locked By ThreadID:2 5
Unlocked By ThreadID:2 5
Unlocked By ThreadID:2 4
Unlocked By ThreadID:2 3
Unlocked By ThreadID:2 2
Unlocked By ThreadID:2 1
Unlocked By ThreadID:2 0
Locked By ThreadID:1 6
Locked By ThreadID:1 7
Locked By ThreadID:1 8
Locked By ThreadID:1 9
Locked By ThreadID:1 10
Locked By ThreadID:1 11
Unlocked By ThreadID:1 11
Unlocked By ThreadID:1 10
Unlocked By ThreadID:1 9
Unlocked By ThreadID:1 8
Unlocked By ThreadID:1 7
Unlocked By ThreadID:1 6
[Finished in 3.6s]
*/
// EXAMPLE 2: With loop
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::recursive_mutex m1;

int main() {
	
	for(int i=0; i<5; i++) {
		m1.lock();
		std::cout << "locked " << i << endl;
	}

	for(int i=4; i>=0; i--) {
		m1.unlock();
		std::cout << "ulocked " << i << endl;
	}
	
	return 0;
}