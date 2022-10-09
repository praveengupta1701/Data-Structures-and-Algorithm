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

int uniquePaths(int m, int n) {
        // TC:- O(N)
        // SC:- O(1)
        int N = m+n-2;
        int r = m-1;
        double res = 1;
        
        // Find nCr
        for(int i=1; i<=r; i++){
            res = res * (N-r+i) / i;
        }
        
        return (int)res;
    }

    //method 2.
/*Take eg: arr[5][5], We can come to position(5,5) from (4,5) and (5, 4)
So if we sum both of them we can get value for (5,5).
The robot can only move right and down, when we see at some point, it either comes from left or above. 
If we use dp[i][j] for the present path to arrive at the point (i, j), then the state equation is dp[i][j] = dp[i][j - 1] + dp[i - 1][j].  
for present value we are using help of previous values.(dynamic programming)*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2d vector for m*n and set value to 1;
        
       // vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Many may confuse by seeing the above line 
        // This is same as dp[m][n] = {0} using array
        int dp[m][n];
        for (int i = 0; i < m; ++i)
            dp[i][0]=1;  
        for (int i = 0; i < n; ++i)
            dp[0][i]=1;   
        
        // iterate to all the grids in m*n and set dp[i][j] = dp[i-1][j] + dp[i][j-1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // Finally result the last grid ans
        return dp[m - 1][n - 1];
        
    }
};
int32_t main()
{   
    /* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/

    Solution s;
    cout<<s.uniquePaths(3,7);

    return 0;
}
