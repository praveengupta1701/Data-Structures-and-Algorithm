// Created by ...
/* Author -Praveen Gupta*/

#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <memory>
#include <condition_variable>
using namespace std;


class A
{
public:

	virtual void show()
	{
		cout<<"in A class";
	}
};

class B: public A
{

public:
 void show()
 {
 	cout<<"in clasa B ";
 }



};






int main()
{
	// A a;

	// a.show();

	// B b;

	// // a=b;
	// // a.show();

	// b=a;
	// b.show();
string a="1234", b="9076";
string ans="",val="";
// int aa='0';
// cout<<aa;
int a_val=0,b_val=0,sum=0, d=0,carry=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		a_val=a[i]-'0';
		// cout<<a_val<<" b";
		b_val=b[i]-'0';
		// cout<<b_val<<" ";

		sum=a_val+b_val+carry;
		carry=0;
		if(sum>9)
		{
			if(sum==10)
			{
				val='0';
				ans=ans+val;
		     	// cout<<val<<" val.";
				carry=1;
			}
			else
			{
			d=sum%10;
			//sum=sum/10;
			val=(d+'0');
			// cout<<val<<" val,";
			ans=ans+val;
			carry=1;
			}
		}
		else
		{	val=(sum+'0');
			// cout<<val<<" val/";
			ans=ans+val;

		}
		sum=0;	
	}

	if(carry==1)
	{
		ans=ans+'1';
	}
	carry =0;
	cout<<"\n\n"<<ans;

	reverse(ans.begin(),ans.end());
	cout<<"\n\n"<<ans;

}









