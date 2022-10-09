
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
    int majorityElement(vector<int>& nums) {
         int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            //count += (candidate == num) ? 1 : -1;
            if(num==candidate) count += 1; 
            else count -= 1; 
        }

        return candidate;
        
    }
};

int32_t main()
{   
     #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif
   

    return 0;
}

