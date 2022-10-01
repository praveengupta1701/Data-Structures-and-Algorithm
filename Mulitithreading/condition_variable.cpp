// TOPIC: Condition Variable In C++ Threading

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition




#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

long balance = 0;
std::mutex m;
std::condition_variable cv;


void addMoney(int money) 
{
	cout<<"\n\nInside addmoney "<<endl;

	std::lock_guard<std::mutex> lg(m);
	balance+=money;
	cout<<"Amount added in curr bal "<<balance<<endl;
	cv.notify_one();
}

void withdrawmoney(int money)
{
	std::unique_lock<mutex> ul(m);
	cout<<"Inside withdraw "<<endl;
	cv.wait(ul,[]{return (balance!=0)? true: false;});

	if(balance>=money)
	{
		balance-=money;
		cout<<"Amount deducted "<<money<<endl;
	}
	else
	{
		cout<<"A can't deducted, cb is less\n";
	}
	cout<<"cb is "<<balance;
}

int main() {
	std::thread t1(withdrawmoney,500);
	// std::thread t1(withdrawmoney,600);
	std::thread t2(addMoney,500);
	std::this_thread::sleep_for(std::chrono::seconds(10));

	t1.join();
	t2.join();

	// cout << balance << endl;
	return 0;
}