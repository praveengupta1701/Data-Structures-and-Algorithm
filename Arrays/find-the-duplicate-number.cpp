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
    int findDuplicate(vector<int>& nums) //t(m)=0(n) and s(n)=O(n)
    {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++)
        {
            if (m.count(nums[i]) != 0)
            {
                return nums[i];
            }
            m[nums[i]]=1; 
        }
        return 0;
    }
    //method 2

    int findDuplicate1(vector<int>& nums)//t(m)=0(n) and s(n)=1 
    {
         int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
    }
};


int32_t main()
{   
    /*#ifndef ONLINE_JUDGE    
    freopen("C:\Users\Praveen\Documents\programs\cpp\input.txt", "r", stdin);
    freopen("C:\Users\Praveen\Documents\programs\cpp\output.txt", "w", stdout);
  #endif*/



    return 0;
}