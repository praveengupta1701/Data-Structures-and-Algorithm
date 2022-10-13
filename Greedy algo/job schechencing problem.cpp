#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int deadline; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);// sorting on profit basis in decending order
      int maxi = arr[0].deadline;
      //max deadline
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].deadline);
      }

      vector<int> slot(maxi + 1,-1);//no job done

  

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++)// already sorted so , i willl come on profit basis
       {
         for (int j = arr[i].deadline; j > 0; j--)
          {
            if (slot[j] == -1)// is job not done j day then do job 
            {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
      // vector<int> ans;
      // ans.push_back(countJobs);
      // ans.push_back(jobProfit);
      // return ans;
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 