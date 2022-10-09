
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int lo = 0;
        int m=matrix.size();
        int n=matrix[0].size();
        if(!m) return false;
        int hi = (m * n) - 1;
        
        while(lo <= hi)
        {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/n][mid % n] == target) 
            {
                return true;
            }
            if(matrix[mid/n][mid % n] < target) 
            {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
};
// Time complexity: O(log(m*n))

// Space complexity: O(1)

int32_t main()
{   
     #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif


    Solution s;
    vector<vector<int>> k;
    vector<int> j={1,2,3,4,5,6};
    k.push_back(j);
    bool t=s.searchMatrix(k,2);
    cout<<t;



    return 0;
}