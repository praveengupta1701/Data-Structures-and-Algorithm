// TOPIC: Shared Pointer In C++

// NOTES:
// 0. shared_ptr is a smart pointer which can share the ownership of object (managed object).
// 1. Several shared_ptr can point to the same object (managed object).
// 2. It keep a reference count to maintain how many shared_ptr are pointing to the same object.
//    and once last shared_ptr goes out of scope then the managed object gets deleted.
// 3. shared_ptr is threads safe and not thread safe. [what is this??]
//    a. control block is thread safe
//    b. managed object is not
// 4. There are three ways shared_ptr will destroyed managed object.
//    a. If the last shared_ptr goes out of scope.
//    b. If you initialize shared_ptr with some other shared_ptr.
//    c. If you reset shared_ptr.
// 5. Reference count doesn't work when we use reference or pointer of shared_ptr.


#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
using namespace std;
/*
 class Foo {
    int x;
    public :
    Foo(int x):x{x} {}
    int getX() { return x; }
    ~Foo() { cout << "~Foo" << endl; }
};



int main(){

    std::shared_ptr<Foo> sp(new Foo(100));
    cout<<sp->getX()<<endl;
    cout<<sp.use_count()<<endl;
    std::shared_ptr<Foo> sp1=sp;//assigning
    cout<<"assigning"<<sp.use_count()<<endl;
    cout<<"assigning"<<sp1.use_count()<<endl;

    std::shared_ptr<Foo> &sp2=sp;//referencing
    cout<<"referencing"<<sp.use_count()<<endl;
    cout<<"referencing"<<sp2.use_count()<<endl;

    std::shared_ptr<Foo> *sp3=&sp;//pointer
    cout<<"pointer "<<sp.use_count()<<endl;

    auto shared_ptr=std::make_shared<int>(100);// for creating object
    return 0;
} */


//Threading
 class Foo {
    int x;
    public :
    Foo(int x):x{x} {}
    int getX() { return x; }
    ~Foo() { cout << "~Foo" << endl; }
};


void fun(std::shared_ptr<Foo> sp) {
        // static std::mutex m1;
        // std::lock_guard<std::mutex> loc(m1);
        cout  << "reference count :- " << sp.use_count() << endl;
}

int main(){

    std::shared_ptr<Foo> sp(new Foo(100));
    cout << "main before: " << sp.use_count() << endl;

    thread t1(fun, sp), t2(fun, sp), t3(fun, sp);

    t1.join(); t2.join(); t3.join();
    return 0;
} 
/*
class Test
{
    private:
    int x;
    public:
    Test(int i):x{i}{}
    ~Test(){ cout << "Dtor" << endl;}
    int getX() const
    {
        return x;
    }
};

void fun(std::shared_ptr<Test> sp, int count)
{
    cout<<"SP count:" <<sp.use_count() << " count:" << count  <<endl;
}

int main(int argc, char const *argv[])
{
    std::shared_ptr<Test> sp(new Test(10));

    cout << sp->getX() << endl;
    cout <<"SP Main: " <<sp.use_count() << endl;
    
    fun(sp,1);
    fun(sp,2);
    fun(sp,3);
    return 0;
}*/