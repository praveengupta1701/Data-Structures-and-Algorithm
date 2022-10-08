#include<iostream>

using namespace std;


class A
{
	
public:
	A()
	{
	 cout<<"Inside A";
	}
ch

	virtual void show()=0;//
	
};

class B:public A
{
public:
	B()
	{
		cout<<"in B";
	}

	void show()
	{
		cout<<"in show() B";
	}

};


int main()
{
	B obj1;
	A *obj_A;
	obj_A=&obj1;
	obj_A.show();

return 0;
}


