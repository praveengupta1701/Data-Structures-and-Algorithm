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
  int trap(vector<int>& height)
    {
    	int n=height.size();
    	int pre[n]={0},suf[n]={0};
    	pre[0]=height[0];
    	for (int i = 1; i < n; ++i)
    		pre[i]=max(pre[i-1],height[i]);
    	suf[n-1]=height[n-1];
    	for (int i =n-2; i >=0 ; --i)
    		suf[i]=max(suf[i+1],height[i]);
    	int watertrap=0;
    	for (int i = 0; i < n; ++i)
    		watertrap+=min(pre[i],suf[i]) - height[i];
    	return watertrap;

    }

class Solution {
public:
    int trapoptimal(vector<int>& height) {
       int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) 
  {
    if (height[left] <= height[right]) 
    {
      if (height[left] >= maxLeft)
        maxLeft = height[left];
       else
        res += maxLeft - height[left];
      
      left++;
    } else 
    {
      if (height[right] >= maxRight) 
        maxRight = height[right];
       else
        res += maxRight - height[right];
      
      right--;
    }
  }
  return res;
}
};
int trapworst(vector < int > & arr) {
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/

	vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<trap(v);


    return 0;
}