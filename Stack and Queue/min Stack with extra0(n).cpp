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

stack<int> s,ss;

void push(int a)
{
	s.push(a);
	if(ss.size()==0||ss.top()>=a)
	{
		ss.push(a);
	}
	return;
}

int pop()
{
	if(s.size()==0)
		return -1;
	int ans=s.top();
	s.pop();
	if(ss.top()==ans)
		ss.pop();
	return ans;
}


int getmin()
{
	if(ss.size()==0)
		return -1;
	return ss.top(); 
}



int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/
	push(5);
	push(3);
	push(6);
	cout<<getmin();


    return 0;
}