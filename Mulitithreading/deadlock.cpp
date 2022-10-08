#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex m1,m2;

void T1() {
	m1.lock();// remove it
	std::this_thread::sleep_for(std::chrono::seconds(5));

	m2.lock();// remove it

cout<<"inside t1\n";
	m1.unlock();//remove it
	m2.unlock();//remove it

}
//here sleep is like that m1 is in sleep and m2  is sleep so resource are not getting free so deadlock
//prevention  mutex.lock should be same order
void T2() {
	// m2.lock();// remove it
	m1.lock();// for prevention in same order as previos
	std::this_thread::sleep_for(std::chrono::seconds(5));
m2.lock();// for prevention in same order as previos
	// m1.lock();// remove it

cout<<"inside t2\n";
	m2.unlock();//remove it
	m2.unlock();//remove it

}



int main() {
	std::thread t1(T1);
	std::thread t2(T2);

	t1.join();
	t2.join();

	return 0;
}