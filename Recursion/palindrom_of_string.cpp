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



bool reverse(int i,string n)//functional
{
	if(i>=n.size()/2) return true;
	if(n[i]!=n[n.size()-i-1]) return false;
	return reverse(i+1,n);	
}

int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/
string n="MADAM";
	cout<<reverse(0,n);
    return 0;
}