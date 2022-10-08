
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
      vector<vector<int>> merge(vector<vector<int>>& intervals) {
                sort(intervals.begin(),intervals.end());

     vector < vector < int >> merged;


//if A[i,j], B[h,k]  here if h > j then new case otherwise add in old one only  or if there is only one isze vector
  for (int i = 0; i < intervals.size(); i++) {
    if (merged.empty() || merged.back()[1] < intervals[i][0]) {
      vector < int > v = {
        intervals[i][0],
        intervals[i][1]
      };

      merged.push_back(v);
    } else {
      merged.back()[1] = max(merged.back()[1], intervals[i][1]);
    }
     
    }
     return merged;}
};


int32_t main()
{   
    /*#ifndef ONLINE_JUDGE    
    freopen("C:\Users\Praveen\Documents\programs\cpp\input.txt", "r", stdin);
    freopen("C:\Users\Praveen\Documents\programs\cpp\output.txt", "w", stdout);
  #endif*/



    return 0;
}