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
/*
//2 pointer single pass
We will make both the iterations, forward and the backward one simultaneously and will appoint 2-pointer at the front and the backend (mentioning it by l(left_prod, it will leave the last -ve number out) and r(right_prod , it will leave the first -ve number out))....will compare the result everytime with both the products(left and right) and will update it with the maximum value encountered till then....
and will do the same thing here too, updating the left_prod and right_prod by 1 whenever they become 0 !!
1-pass optimal solution(2-pointer)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0], l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            l =  (l) * nums[i];
            r =  (r) * nums[n - 1 - i];
            res = max(res, max(l, r));
            if(l==0)l=1;
            if(r==0)r=1;
        }
        return res;
    }
};
 int maxProduct(vector<int> A) {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * A[i];
            r =  (r ? r : 1) * A[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
/*
Example -->>> arr={-2,1,4,5,0,-3,4,6,1,-2} .... so we can consider subarray1={-2,1,4,5} and subarray2={-3,4,6,-2} and then the max_ans(subarray1,subarray2) will be our answer !!

Let's have a look on our code now ....

2-pass solution(for better understanding)*/

class Solution1 {
public:
   int maxProduct(vector<int>& nums) {
       
       int curr_product = 1, res = INT_MIN;
       
       for (auto i: nums) {
           curr_product = curr_product * i;
           res = max(curr_product, res);
           if(curr_product == 0) {
               curr_product = 1;
           }
       }
       
       curr_product = 1;
       
       for (int i = nums.size()-1; i>=0; i--) {
           curr_product = curr_product * nums[i];
           res = max(curr_product, res);
           if(curr_product == 0) {
               curr_product = 1;
           }      
       }
       return res;
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