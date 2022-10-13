#include <Windows.h>
#include <iostream>

using namespace std;


class SingletonClass {

public:
    static SingletonClass* getInstance() {

    return (!m_instanceSingleton) ?
        m_instanceSingleton = new SingletonClass : 
        m_instanceSingleton;
    }

private:
    // private constructor and destructor
    SingletonClass() { cout << "SingletonClass instance created!\n"; }
    ~SingletonClass() {}

    // private copy constructor and assignment operator
    SingletonClass(const SingletonClass&);
    SingletonClass& operator=(const SingletonClass&);

    static SingletonClass *m_instanceSingleton;
};

SingletonClass* SingletonClass::m_instanceSingleton = nullptr;



int main(int argc, const char * argv[]) {

    SingletonClass *singleton;
    singleton = singleton->getInstance();
    cout << singleton << endl;

    // Another object gets the reference of the first object!
    SingletonClass *anotherSingleton;
    anotherSingleton = anotherSingleton->getInstance();
    cout << anotherSingleton << endl;

    Sleep(5000);

    return 0;
}
/*
Only one object created and this object reference is returned each and every time afterwords.

SingletonClass instance created!
00915CB8
00915CB8
Here 00915CB8 is the memory location of singleton Object, same for the duration of the program but (normally!) different each time the program is run.

N.B. This is not a thread safe one.You have to ensure thread safety.*/