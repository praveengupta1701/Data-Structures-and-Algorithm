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


int print(int ind,int s,int sum,int a[],int n)//functional
{
	if(ind==n)
	{//condition satisfied
		if(s==sum)
			return 1;
	 	else//condition not satisfied
			return 0;
}
	//take or pick the particular index into the subsequence
	s+=a[ind];
	int l=(print(ind+1,s,sum,a,n));

	s-=a[ind];
	//not pick or not take condition , this element is not added to your subsequence
	int r=(print(ind+1,s,sum,a,n));
		
	return r+l;
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
	cout<<print(0,0,sum,a,n)<<endl;
    return 0;
}