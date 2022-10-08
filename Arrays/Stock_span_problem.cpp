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


int maxProfit(vector<int>& arr)
    {
        int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
        
    }

int32_t main()
{   
	#ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> v={100,80,60,70,60,75,85};
	int ans;
	ans=maxProfit(v);


	cout<<ans<<endl;


    return 0;
}