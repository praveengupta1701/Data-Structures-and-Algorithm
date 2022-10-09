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
int solve(vector<int>  a){
	int  maxi = 0;
	for(int i = 0; i < a.size(); ++i){
		int sum = 0;
		for(int j = i; j < a.size(); ++j){
			sum += a[j];
			if(sum == 0){
				maxi = max(maxi, j-i+1);
			}
		}
	}
	return maxi;
   }
int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}
int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/
int a[]={1,4,-6,1,3,7,-8,4,-6,8};
	cout<<maxLen(a,10);

    return 0;
}