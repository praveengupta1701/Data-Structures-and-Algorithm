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

int sum(int n)//functional
{
	if(n==0) return 0;
	return n+sum(n-1);	
}
void sum1(int i,int sum)//parameter
{
	if(i<1) 
		{cout<<sum;
		return;
		}
	return sum1(i-1,sum+i);	
}


int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/
	
	int n=3;
	cout<<sum(n);
	sum1(4,0);

    return 0;
}