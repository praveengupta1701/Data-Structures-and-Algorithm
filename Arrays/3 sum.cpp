#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        int n=num.size();
        // moves for a
        for (int i = 0; i < (int)(n)-2; i++)
         {    
            if (i == 0 || (i > 0 && num[i] != num[i-1])) 
            {      
                int lo = i+1;
                int hi = (int)(n)-1;
                int sum = 0 - num[i]; // sum is target

                // from here i is 2 sum problem by 2 pointer approch
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) 
                    {
                        res.push_back({num[i],num[lo],num[hi]});
                        //jumping over duplicates to next different element
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;

                        //if different    
                        lo++; hi--;
                    }
                    // greater  than sum low ++
                    else if (num[lo] + num[hi] < sum) lo++;
                    // less  than sum hi --                  
                    else hi--;
               }
            }
        }
        return res;
    }

vector < vector < int >> naivethreeSum(vector < int > & nums) {
  vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;
}
int main() {
  vector < int > arr{-1,0,1,2,-1,-4};
  vector < vector < int >> ans;
  ans = threeSum(arr);
  cout << "The triplets are as follows: "<< endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] <<" ";
    }
    cout << endl;
  }
  return 0;
}