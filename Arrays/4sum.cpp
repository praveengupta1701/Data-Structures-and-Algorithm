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

vector<vector<int>> fourSum(vector<int>& nums, int target) //t(n)=n3logn
{	 vector<vector<int>> ans; 
		if (nums.empty())
            return ans;
        int n = nums.size();  
        sort(nums.begin() , nums.end());  // sort the array to use the two pointers method
        
        set<vector<int>> store;   // to store and remove the duplicate answers
		
        for(int i = 0 ; i < n; i++){
		
            for(int j = i + 1; j < n ; j++){
			 //overflowing int,that's why *1L(typecasting to long)
                long long new_target  =  (long long)target - nums[i] - nums[j];
                
                int front = j+1 , back = n-1;
                
                while(front < back){
				
                    int sum = nums[front] + nums[back];
                    
                    if(sum > new_target) back--;
                    else if(sum < new_target ) front++;
                    else  {
                        store.insert({nums[i] , nums[j] , nums[front] , nums[back]});//insert takes logn
                        front++;
                        back--;
                    }
                }
            }
        }
		
        for(auto i : store){
            ans.push_back(i);  // store the answers in an array(ans)
        }
		
        return ans;
    }

int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/



    return 0;
}


class Solution {
public:
vector<vector<int>> fourSum(vector<int>& num, int target) //t(n)=n3
{
 vector<vector<int> > res;
if (num.empty())
    return res;

int n = num.size(); 
sort(num.begin(),num.end());
int index=0;
for (int i = 0; i < n; i++) {

    long long target_3 = (long long)target - num[i];

    for (int j = i + 1; j < n; j++) {
    
    long long target_2 = (long long)target_3 - num[j];

    int front = j + 1;
    int back = n - 1;

    while(front < back) {
    
        int two_sum = num[front] + num[back];
    
        if (two_sum < target_2) front++;
    
        else if (two_sum > target_2) back--;
    
        else {
        res.push_back({num[i],num[j],num[front],num[back]});
    	
        // Processing the duplicates of number 3 jumping over dupicates
        while (front < back && num[front] == res[index][2]) ++front;
    
        // Processing the duplicates of number 4
        while (front < back && num[back] == res[index][3]) --back;

        index++;
    
        }
    }
    
    // Processing the duplicates of number 2
    while(j + 1 < n && num[j + 1] == num[j]) ++j;
    }

    // Processing the duplicates of number 1
    while (i + 1 < n && num[i + 1] == num[i]) ++i;

}

    return res;
}
};