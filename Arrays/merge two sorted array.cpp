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


class Solution 
{
public:
   
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) //t(n)=O(nlogn) and S(n)=1
     {
int j=0;
for(int i=m;i<(m+n);i++)
{
nums1[i]=nums2[j];
j++;
}
sort(nums1.begin(), nums1.end());
}
};

//method 2

    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) //t(n)=O(n) and S(n)=n
    {
           int k=0;
        int i=0;
        int j=0;
        vector<int> nums3;
        while(i<m and j<n){
            if(nums1[i]<nums2[j])
                nums3.push_back(nums1[i++]);
        else
            nums3.push_back(nums2[j++]);
        }
        
        while(i<m){
            nums3.push_back(nums1[i++]);
        }
        while(j<n){
            nums3.push_back(nums2[j++]);
        }
    nums1=nums3;
    }

//method3 // optimised
 void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) //t(n)=O(n) and S(n)=1
 {
    int i = m - 1, 
        j = n - 1, 
        k = m + n - 1;

    while (i >= 0 && j >= 0)
        nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

    // if i >= 0 at this point, means that nums2 was fully iterated 
    // and nums1 already has the remaning elements in the right place;
    // therefore, only handle the j >= 0 scenario
    
    while (j >= 0)
        nums1[k--] = nums2[j--];
    }

int32_t main()
{   
    /*#ifndef ONLINE_JUDGE    
    freopen("C:\Users\Praveen\Documents\programs\cpp\input.txt", "r", stdin);
    freopen("C:\Users\Praveen\Documents\programs\cpp\output.txt", "w", stdout);
  #endif*/
    Solution a;
    vector<int> s={1,2,0,0},b={3,4};
    a.merge(s,4,b,2);


    return 0;
}