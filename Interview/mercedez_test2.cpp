
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class A
{
    private:
    int a;
    char b;
    public:
    
    A()
    {
        
    }
    void set_int(int x)
    {
        a=x;
    }
    int get_int()
    {
        return a;
    }
    int add(int x , int y=5)
    {
        return x+y;
    }
    double add(float x , float y, double z)
    {
        return x+y;
    }
    float add(float x , float y, float z=1)
    {
        return x+y+z;
    }
    // virtual void show()=0;
};

// class B :public A
// {
// public:
// void show()
// {
//     cout<<"in B";
// }
// };
// A::show()
// {
    
// }
// template <class A>
// A sum(A a,A b)
// {
//     return a+b;
// }

int main()
{
    A a;
    // A *a1;
    // B b1;
    // a1=&b1;
    // a1->show();
    // // cout<<" "<<sum(1,3);
    // // cout<<" "<<sum(1.1,3.1);
    
    // std::vector<int> x={1,2,3,4,5} ;
    
    // for_each(x.begin(),x.end(),[](int i){ cout<<i<<" ";});
    
    return 0;
}