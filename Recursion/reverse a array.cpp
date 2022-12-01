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



void reverse(int i,int a[].int n)//functional
{
	if(i>=n/2) return ;
	swap(a[i],a[n-i-1]);
	reverse(i+1,a,n);	
}

int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/
	
	int n=5;
	int a[]={1,2,3,4,5};
	for (int i = 0; i < n; ++i)cout<<a[i]<<" ";
	reverse(0,a,n);
for (int i = 0; i < n; ++i)cout<<a[i]<<" ";
    return 0;
}