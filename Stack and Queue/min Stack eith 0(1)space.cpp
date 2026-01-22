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

stack<int> s;
int minEle;

void push(int a)
{
	if(s.size()==0)
	{
	s.push(a);
	minEle=a;
	}
	else
	{
	if(a>=minEle)
		s.push(a);
	else if(a<minEle)
		s.push(2*a - minEle);
	}	
	return;
}

int pop()
{
	if(s.size()==0)
		return -1;
	int ans=s.top();
	if(s.top()>=minEle)
	s.pop();
	else if(s.top()<minEle)
	{
		minEle=2 * minEle -s.top();
		s.pop();
	}
	return ans;
}

int top()
{
	if(s.size()==0)
		return -1;
	else
	{
	if(s.top()>=minEle)
		return s.top();
	else if(s.top()<minEle)
	{
		return minEle;
	}
	}
	return 0;
}

int getmin()
{
	if(s.size()==0)
		return -1;
	return minEle; 
}



int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/
	push(5);
	push(3);
	cout<<s.top()<<" "<<top()<<" "<<minEle<<" ";
	push(6);
	cout<<endl;
	cout<<pop();
	cout<<endl;
	cout<<pop()<<" "<<s.top()<<" "<<top()<<" "<<minEle<<" ";
	cout<<endl;
	cout<<getmin();


    return 0;
}