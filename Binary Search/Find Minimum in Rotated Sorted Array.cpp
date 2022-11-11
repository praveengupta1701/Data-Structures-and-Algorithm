


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

int findMin(vector<int> );
int32_t main()
{   
    /* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/



    return 0;
}


int findMin(vector<int> &num){
        int start=0,end=num.size()-1;
        
        while(start<end) {
            if(num[start]<num[end])
                return num[start];
            
            int mid = (start+end)/2;
            
            if(num[mid]>=num[start]) {
                start = mid+1;
            } else{
                end = mid;
            }
        }
        
        return num[start];
    }
