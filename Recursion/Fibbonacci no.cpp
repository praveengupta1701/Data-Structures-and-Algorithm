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



int f(int n)//functional
{
	if(n<=1) return n;
	int last=f(n-1);
	int slast=f(n-2);
	return last+slast;	
}

int32_t main()
{   
	 #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif
int  n=6;
	cout<<f(n);
    return 0;
}