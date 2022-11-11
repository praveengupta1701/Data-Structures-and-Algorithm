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

//Extention of  Find Minimum in Rotated Sorted Array Question
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
     
        int start=0;
        int n=nums.size();
        int end=n-1,mid,realmid;
        int k=0;
        while(start<end)
        {
            if(nums[start]<nums[end])
            {
              k=start;
              break;
            }
            mid=(start+end)>>1;
            if(nums[mid]>=nums[start])
                start=mid+1;
            else
                end=mid;
        }
        if(k==0)
        {
            k=start;
        }
        start=0;
        end=n-1;
        // The usual binary search and accounting for rotation.
        while(start<=end){
            mid=(start+end)>>1;
            realmid=(mid+k)%n;// main line
            if(nums[realmid]==target)return realmid;
            if(nums[realmid]<target)start=mid+1;
            else end=mid-1;
        }
        return -1;
    }
};
int32_t main()
{   
    /* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/



    return 0;
}