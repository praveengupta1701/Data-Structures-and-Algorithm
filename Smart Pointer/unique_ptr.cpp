// TOPIC: Unique Pointer In C++

// NOTES:
// 0. unique_ptr is a class template.
// 1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
// 2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer,
//    when unique_ptr object goes out of scope.
// 3. similar to actual pointers we can use -> and * on the object of unique_ptr, 
//    because it is overloaded in unique_ptr class.
// 4. When exception comes then also it will de-allocate the memory hence no memory leak.
// 5. Not only object we can create array of objects of unique_ptr.

// OPERATIONS:
// release, reset, swap, get, get_deleter.


// PROGRAM: 
/*
#include<iostream>
#include<memory>
using namespace std;

class Foo {
        int x;
    public:
        explicit Foo(int x): x{x} {}
        int getX() { return x; }
    ~Foo() { cout << "Foo Dest" << endl; }
};

int main() {

    // Foo *f = new Foo(10);
    // cout << f->getX() << endl;
    // delete f;

    std::unique_ptr<Foo> p(new Foo(10));
    cout << p->getX() << endl;

    return 0;
}*/

#include <iostream>
#include <memory>
#include <iomanip>
#include <thread>
#include <mutex>
using namespace std;

class Foo {
        int x;
    public:
        explicit Foo(int x): x{x} {}
        int getX() { return x; }
    ~Foo() { cout << "Foo Dest" << endl; }
};

int main() {

    // Foo *f = new Foo(10);
    // cout << f->getX() << endl;
    // delete f;// we have to write it if we don't want memory leak

    std::unique_ptr<Foo> p1(new Foo(10));
    std::unique_ptr<Foo> p2(new Foo(100));
    std::unique_ptr<Foo> p3=make_unique<Foo>(20);

    cout << p1->getX() << endl;
    cout << (*p3).getX() << endl;

     //p1=p2 // FAIL: this will fail because you can not copy owership.

    std::unique_ptr<Foo> p4=move(p1);//PASS : moving owership is allowed now p1 will become null pointer

    Foo* p=p4.get();
    Foo* p5=p4.release();

    p3.reset(p5);
    cout<<p3->getX();

    return 0;
}
