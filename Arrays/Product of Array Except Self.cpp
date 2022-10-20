
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

//Divide Question in three part :- more than one zero , one zero , no zero
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul=1,k=0,index_0;
        int n=nums.size();
        for(auto i=0;i<n;i++)
        {
             if(nums[i]==0)
            {
                k++;//counting no zeros
                index_0=i;// index of zero
                continue;// we don't to  mul=0  if there is only one zero we can directly use it
            }
            mul*=nums[i];
        }
        // vector<int> ans(nums.size());
        //1. if there are more than one zero
        if(k>1)
        {
            nums.assign(n,0);
            return nums;
        }
        //2.if there is one zero
        else if(k==1) 
        {
            nums.assign(n,0);
            nums[index_0]=mul;// since there is one zero so we have to assign that index only
            return nums;
        }

        //3. if there is no zero
        int d=0;
        for(auto i=0;i<n;i++)
        {  
            d=mul/nums[i];// we can just divide by element to get ans
            nums[i]=(d);
        }
        return nums;
        
    }
};

int32_t main()
{   
     #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif

    vector<int> a={-1,1,2,-3,1},ans;
    Solution s;
    ans=s.productExceptSelf(a);
    for_each(ans.begin(),ans.end(),[](int a){cout<<a<<" ";});
    

    return 0;
}