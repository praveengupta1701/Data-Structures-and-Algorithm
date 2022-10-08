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

vector<int> nextPermutation(vector<int>& nums)
    {
     //   next_permutation(nums.begin(),nums.end());// metod 1.
    	int i=nums.size(),index=-1;
    	for(auto j=i-1;j>0;j--)
    	{
    		if(nums[j-1]<nums[j])
    		{
    			index=j-1;
    			break;
    		}
    	}
    	if(index==-1)
    	{
    		reverse(nums.begin(),nums.end());
    	}
    	else
    	{
    		 int id=-1;
    		for(auto k=i-1;k>index;k--)
    		{
    			if(nums[index]<nums[k])
    			{
    				id=k;
    				break;
    			}
    		}
    		swap(nums[index],nums[id]);
    		reverse(nums.begin()+index+1,nums.end());
    	}
    	return nums;
    }

int32_t main()
{   
	#ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v={1,2,3};
	vector<int> ans=nextPermutation(v);
	for_each(ans.begin(),ans.end(),[](int x){cout<<x<<" ";});

    return 0;
}