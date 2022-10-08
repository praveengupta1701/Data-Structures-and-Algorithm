#include <iostream>
using namespace std;

void f1()
{ int f1=2;
	cout<<"f1 "<<f1;
}

void f2()
{int f2=3;
	cout<<"f2 "<<f2;
	f1();
}

void f3()
{    
	int f3=4;
	cout<<"f3"<<" "<<f3;
	f2();
}

int main(int argc, char const *argv[])
{ int f=1;
	cout<<f<<"f"<<"\n";
	f3();
	return 0;
}

