
// Created by ...
/* Author -Praveen Gupta*/

#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <memory>
#include <condition_variable>
using namespace std;
using namespace std::chrono;


// int32_t main()
// {   
// 	 #ifndef ONLINE_JUDGE    
//     freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
//     freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
//   #endif



//     return 0;
// }
// struct A {

// A() = default;

// virtual ~A() = default;

// virtual void f() {cout<<"a"; }

// };

// struct B: public A {

// B(): A() { f();

// } virtual void f() {cout<<"b";}


// };

// struct C: public B {

// C() : B() { } virtual void f() {
// cout<<"c"; }

// };

// int main() {

// C C;
// }



// void foo(int x) {

// std::cout << "foo(int)" << x << " ";

// } struct A {

// void foo(double d) const {

// std::cout << "A::foo (double)" << d << " ";

// }

// void bar(int x) const {

// foo(x);

// }

// };

// int main() {

// A a;

// a.bar(17);
// }

// 




// struct Taxpayer {

// virtual ~Taxpayer () = default; 
// virtual std::string data() const 
// {
//  return "";

// }

// };

// struct Private :public Taxpayer 
// {
//  std::string name_ = "John Doe";
//   std::string data() const override 
//   {

// return name_;

// }

// };

// struct Firm: public Taxpayer {

// std::string businessLine_ = "trafficking"; 
// std::string data() const override 
// {
//  return businessLine_;

// }

// };

// struct SelfEmployed : public Private, public Firm 
// {
//  std::string data() const override 
//  {
//   return name_ + " "+ businessLine_;
// }
// };


// std::string print1 (Taxpayer t) {

// return t.data();

// }

// std::string print2 (const Taxpayer& t) {

// return t.data();

// }

// int main() {

// SelfEmployed doe; 
// // print1(doe);
// print2(doe);

// }



// struct Taxpayer {

// int id_ = 0;

// virtual std::string Data() const { return std::to_string(id_);

// }

// };

// struct Business: public Taxpayer { std::string brand_ = "racket plc"; std::string Data() const override { return brand_ + " "+ Taxpayer::Data();

// }

// };

// void print(Taxpayer t) {

// std::cout << t.Data() << std::flush;

// }

// std::unique_ptr<Taxpayer> getTaxpayer() { return std::make_unique<Business>();

// }

// void run() {

// auto t= getTaxpayer(); 
//  if(t) { print(*t);
//  }
// } 

//  int main()

// {
// std::thread t2{ []{ while(true) { std::this_thread::yield(); cout<<"h"; } } };

//  }




// #include <functional>

// struct account

// {

// int balance;

// std::mutex mtx;

// };

// // constraint: the operation should appear atomic 
// void transfer (int amount, account & from, account & to) {

// std::lock_guard<std::mutex> lock1 {from.mtx};
// std::lock_guard<std::mutex> lock2{ to.mtx };

// from.balance -= amount;

// to.balance += amount;

// }

// int main()
// {
// account acc1{ 100 };

// account acc2{ 100 };

// std::thread t1{ transfer, 50, std::ref(acc1), std::ref(acc2) };

// std::thread t2{ transfer, 75, std::ref(acc2), std::ref(acc1) };

// t1.join();

// t2.join();

// }

struct Base
{
virtual ~Base ()= default;
};
using BasePtr = std::unique_ptr<Base>;

struct Derived: public Base
{};
using DerivedPtr = std::unique_ptr<Derived>;

DerivedPtr producer();

void consumer (BasePtr p);

void useIt_1()
{
consumer( producer() );
}
void useIt_2()
{
auto p = producer();

consumer(std::move (p) );
}