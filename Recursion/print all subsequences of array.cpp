// Created by ...
/* Author -Praveen Gupta*/

#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <memory>
#include <condition_variable>
using namespace std;
using namespace std::chrono;



void print(int ind,vector<int> ds,int a[],int n)//functional
{
	if(ind==n)
	{
		for(auto it:ds)
		{
			cout<<it<<" ";
		}
		if(ds.size()==0)
		{
			cout<<"{}";
		}
		cout<<endl;
		return;
	} 
	//take or pick the particular index into the subsequence
	ds.push_back(a[ind]);
	print(ind+1,ds,a,n);
	//not pick or not take condition , this element is not added to your subsequence
	ds.pop_back();
	print(ind+1,ds,a,n);


	

}
void print_reverse(int ind,vector<int> ds,int a[],int n)//functional
{
	if(ind==n)
	{
		for(auto it:ds)
		{
			cout<<it<<" ";
		}
		if(ds.size()==0)
		{
			cout<<"{}";
		}
		cout<<endl;
		return;
	} 

	//take or pick the particular index into the subsequence
	// ds.push_back(a[ind]);
	// print(ind+1,ds,a,n);
	// //not pick or not take condition , this element is not added to your subsequence
	// ds.pop_back();
// print(ind+1,ds,a,n);

	//reverse
	//take or pick the particular index into the subsequence
	print_reverse(ind+1,ds,a,n);
	ds.push_back(a[ind]);
	print_reverse(ind+1,ds,a,n);
	ds.pop_back();
	//not pick or not take condition , this element is not added to your subsequence
	

}
int32_t main()
{   
	 #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif
  int a[]={3,2,1};
	int  n=3;
	vector<int> ds,dsr;
	print(0,ds,a,n);
	cout<<endl;
	print_reverse(0,dsr,a,n);
    return 0;
}