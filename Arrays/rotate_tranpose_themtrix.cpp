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

class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        
    }
};
int32_t main()
{   
	/*#ifndef ONLINE_JUDGE    
    freopen("C:\Users\Praveen\Documents\programs\cpp\input.txt", "r", stdin);
    freopen("C:\Users\Praveen\Documents\programs\cpp\output.txt", "w", stdout);
  #endif*/

	int a[4][4]={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<4;j++)
		{
			a[i][j]=a[j][i];
			// cout<<a[i][j]<<" ";
		}
		// cout<<endl;
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			 cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

    return 0;
}