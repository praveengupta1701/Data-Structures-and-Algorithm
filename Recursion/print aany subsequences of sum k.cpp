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


bool print(int ind,vector<int> ds,int s,int sum,int a[],int n)//functional
{
	if(ind==n)
	{//condition satisfied
		if(s==sum)
		{
			for(auto it:ds)cout<<it<<" ";
		cout<<endl;
		return true;
	}
	else//condition not satisfied
	{
		return false;
	} 
}
	//take or pick the particular index into the subsequence
	ds.push_back(a[ind]);
	s+=a[ind];
	if(print(ind+1,ds,s,sum,a,n)==true)
		return true;

	s-=a[ind];
	//not pick or not take condition , this element is not added to your subsequence
	ds.pop_back();
	if(print(ind+1,ds,s,sum,a,n)==true)
		return true;
	
	return false;
}
int32_t main()
{   
	 // #ifndef ONLINE_JUDGE    
  //   freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
  //   freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  // #endif
    int a[]={1,2,1,0,1};
	int  n=5;
	int sum=2;
	vector<int> ds;
	print(0,ds,0,sum,a,n);
    return 0;
}