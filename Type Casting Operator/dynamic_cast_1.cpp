// C++ program demonstrate if there
// is no virtual function used in
// the Base class
/*
#include <iostream>
using namespace std;

// Base class declaration
class Base {
	void print()
	{
		cout << "Base" << endl;
	}
};

// Derived Class 1 declaration
class Derived1 : public Base {
	void print()
	{
		cout << "Derived1" << endl;
	}
};

// Derived class 2 declaration
class Derived2 : public Base {
	void print()
	{
		cout << "Derived2" << endl;
	}
};

// Driver Code
int main()
{
	Derived1 d1;

	// Base class pointer hold Derived1
	// class object
	Base* bp = dynamic_cast<Base*>(&d1);
	 if (bp == nullptr)
	 	cout << "null" << endl;
	 else
	 	cout<<"not null\n";
	// Dynamic casting
	//Derived2* dp2 = dynamic_cast<Derived2*>(bp);
	//Virtual functions include run-time type information and there is no 
	virtual function in the base class. So this code generates an error.
	// if (dp2 == nullptr)
	// 	cout << "null" << endl;

	return 0;
}
*/


//Case 1: Let’s take an example of dynamic_cast which 
//demonstrates if the casting is successful, it returns a value of type new_type.
// C++ Program demonstrates successful
// dynamic casting and it returns a
// value of type new_type
/*
#include <iostream>

using namespace std;
// Base Class declaration
class Base {
	virtual void print()
	{
		cout << "Base" << endl;
	}
};

// Derived1 class declaration
class Derived1 : public Base {
	void print()
	{
		cout << "Derived1" << endl;
	}
};

// Derived2 class declaration
class Derived2 : public Base {
	void print()
	{
		cout << "Derived2" << endl;
	}
};

// Driver Code
int main()
{
	Derived1 d1;

	// Base class pointer holding
	// Derived1 Class object
	Base* bp = dynamic_cast<Base*>(&d1);

	// Dynamic_casting
	Derived1* dp2 = dynamic_cast<Derived1*>(bp);// change here Derived2
	if (dp2 == nullptr)
		cout << "null" << endl;
	else
		cout << "not null" << endl;

	return 0;
}
*/
// Explanation: In this program, there is one base class and two derived classes 
// (Derived1, Derived2), here the base class pointer hold derived class 1 object 
// (d1). At the time of dynamic_casting base class, the pointer held the Derived1
//  object and assigning it to derived class 1, assigned valid dynamic_casting. 

// Case 2: Now, If the cast fails and new_type is a pointer type, it returns a
//  null pointer of that type.

// C++ Program demonstrate if the cast
// fails and new_type is a pointer type
// it returns a null pointer of that type
#include <iostream>
using namespace std;

// Base class declaration
class Base {
	virtual void print()
	{
		cout << "Base" << endl;
	}
};

// Derived1 class declaration
class Derived1 : public Base {
	void print()
	{
		cout << "Derived1" << endl;
	}
};

// Derived2 class declaration
class Derived2 : public Base {
	void print()
	{
		cout << "Derived2" << endl;
	}
};

// Driver Code
int main()
{
	Derived1 d1;
	Base* bp = dynamic_cast<Base*>(&d1);

	// Dynamic Casting
	Derived2* dp2 = dynamic_cast<Derived2*>(bp);// change
	if (dp2 == nullptr)
		cout << "null" << endl;

	return 0;
}

// Explanation: In this program, at the time of dynamic_casting base class pointer 
// holding the Derived1 object and assigning it to derived class 2, which is not 
// valid dynamic_casting. So, it returns a null pointer of that type in the result.
// Note:

// A Dynamic_cast has runtime overhead because it checks object types at run time using “Run-Time Type Information“.
// If there is a surety we will never cast to wrong object then always avoid dynamic_cast and use static_cast. 