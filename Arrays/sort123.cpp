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

 void sortColors(vector<int>& nums) 
    {
        int i_0=0,i_c=0;   
        for(int k=0;k<nums.size();k++)
        {
         switch(nums[k])
         {
            case 0:
            i_0++;
            break;
            case 1:
            i_c++;
            break;
         }
        }
        for(int k=0;k<nums.size();k++)
        {
         if(i_0>0)
         {
            nums[k]=0;
            i_0--;
         }
         else if(i_c>0)
         {
            nums[k]=1;
            i_c--;
         }
         else
         {
            nums[k]=2;
         }
        }
      
        
    }
int32_t main()
{   
   /*#ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif*/
        #ifndef ONLINE_JUDGE    
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
       #endif



    return 0;
}
