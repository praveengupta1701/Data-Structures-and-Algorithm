// TOPIC: Introduction To Smart Pointers

// NOTES:
// 0. Smart pointer is a class which wraps a raw pointer, to manage the life time of the pointer.
// 1. The most fundamental job of smart pointer is to remove the chances of memory leak.
// 2. It makes sure that the object is deleted if it is not reference any more.

// TYPES:
// 1. unique_ptr : 
//    Allows only one owner of the underlying pointer.

// 2. shared_ptr : 
//    Allows multiple owners of the same pointer (Reference count is maintained).

// 3. weak_ptr : 
//    It is special type of shared_ptr which doesn't count the reference.

#include<iostream>
using namespace std;

class MyInt {
    public:
        explicit MyInt(int *p=nullptr) { data = p; }
// after program goes out of main() then destructer will be called so we don't need to mind the for freeing or deleting pointer it will automatically=t deleted
        ~MyInt() { delete data; }//this destructor will be called after main() for deleting pointer
        int& operator * () { return *data; }
    private:
        int *data;
};

int main() {
    int* p = new int(10);
    MyInt myint = MyInt(p);
    cout << *myint << endl;
    return 0;
}

// after program goes out of main() then destructer will be called so we don't need to mind the for freeing or deleting pointer it will automatically=t deleted