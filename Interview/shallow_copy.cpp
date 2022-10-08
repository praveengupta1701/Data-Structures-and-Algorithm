#include<iostream>
using namespace std; 
  
class PrepInsta 
{ 
public:
    int *var; 
    
    PrepInsta(int x) {
        var=new int;
        *var=x;
    } 
  
    void setvalue(int x)
    {
        *var=x;
    }
    int getvalue()
    {
        return *var;
    }
    // Overriding default copy constructor 
    // with user defind copy contructor
}; 
  
int main() 
{
    // calling the normal constructor
    PrepInsta obj1(10);
    
    // calling user defined copy constructor (Deep Copy)
    PrepInsta obj2 = obj1; 
  
    cout << "Before value change - " << endl;
    
    // printing the values, assigned by constructors
    cout << "obj1.var = " << obj1.getvalue() << endl; 
    cout << "obj2.var = " << obj2.getvalue() << endl;
    
    obj1.setvalue(20);
    
    cout << "\nAfter value change - " << endl;
    
    // printing the values, assigned by constructors
    cout << "obj1.var = " << obj1.getvalue() << endl; 
    cout << "obj2.var = " << obj2.getvalue() << endl;
    
    // since we did deep copy using user defined copy constructor
    // change in obj1 is not reflected in obj2

    return  0; 
}