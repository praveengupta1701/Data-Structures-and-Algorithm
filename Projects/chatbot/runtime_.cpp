#include <iostream>

using namespace std;
class A {
public:
    virtual void show() {
        cout << "In A" << endl;
    }
};

class B : public A {
private:
    void show() {
        cout << "In B" << endl;
    }
};

int main()
{
    A* a = new B();
    a->show();
    // cout<<"Hello World";

    return 0;
}


