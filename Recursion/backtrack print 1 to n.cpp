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

void f_backtrack(int i,int n)
{
	if(i<1)
		return;
	f_backtrack(i-1,n);
	cout<<i<<" ";
}
void f(int i,int n)
{
	if(i>n)
		return;
	cout<<i<<" ";
	f(i+1,n);	
}

int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/
	f_backtrack(7,7);
	cout<<endl;
	f(1,7);



    return 0;
}