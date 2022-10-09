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

vector<int> naivetwoSum(vector<int>& nums, int target)
//Time Complexity: O(N2)
 {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
   	 for (int j = i + 1; j < nums.size(); ++j) {
   		 if (nums[i] + nums[j] == target) {
   			 res.emplace_back(i);
   			 res.emplace_back(j);
   			 break;
   		 }
   	 }
   	 if (res.size() == 2)
   		 break;
    }
    return res;
} 

/*
Dry Run: Given array, nums = [2,1,3,4], target = 4

First we sort the array. So nums after sorting is [1,2,3,4]
We take two pointers, i and j. i points to index 0 and j points to index 3.
Now we check if nums[i] + nums[j] == target. In this case, they don’t sum up, and nums[i] + nums[j] > target, so we will reduce j by 1.
Now, i = 0, j=2
Here, nums[i] + nums[j] == 1 + 3 == 4, which is the required target, so we store both the elements and break the loop.
Now, we run another loop to find the indices of the elements in the actual array, i.e [2,1,3,4]
Then, return the actual indices, [1,2].
*/
vector<int> twopointer_twoSum(vector<int>& nums, int target) {

    	vector<int> res,store;
    	store = nums;

    	sort(store.begin(), store.end());

    	int left=0,right=nums.size()-1;
    	int n1,n2;

    	while(left<right){
        	if(store[left]+store[right]==target){

            	n1 = store[left];
            	n2 = store[right];

            	break;

        	}
        	else if(store[left]+store[right]>target)
            	    right--;
        	else
            	    left++;
    	}

    	for(int i=0;i<nums.size();++i){

        	if(nums[i]==n1)
            	    res.emplace_back(i);
        	else if(nums[i]==n2)
            	    res.emplace_back(i);
    	}

    	    return res;
	}


//hashmap

vector<int> twoSum(vector<int>& nums, int target) {

     vector<int> res;
    unordered_map<int, int> mp;
    int n=nums.size();
    for (int i = 0; i < n; ++i) {

   	 if (mp.find(target - nums[i]) != mp.end()) {

   		 res.emplace_back(i);
   		 res.emplace_back(mp[target - nums[i]]);
   		 return res;
   	 }

   	 mp[nums[i]] = i;
    }

    return res;
}
int32_t main()
{   
	 #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif

	vector<int> v,k={1,4,5,6,2};
	v=twoSum(k,6);
	cout<<v[0]<<" "<<v[1];

    return 0;
}