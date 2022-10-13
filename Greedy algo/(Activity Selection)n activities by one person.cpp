#include <bits/stdc++.h>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};

class Solution {
   public:
      bool static comparator(struct meeting m1, meeting m2) 
      {
         if (m1.end < m2.end) return true;//if finishing time is lesser return true
         else if (m1.end > m2.end) return false;//if finishing time is greather return false then pair has to be swapped
         else if (m1.pos < m2.pos) return true;// sort according to the position or priority
         return false;
      }
   void maxactivitys(int s[], int e[], int n) {
      struct meeting meet[n];
      for (int i = 0; i < n; i++) {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
      }

      sort(meet, meet + n, comparator);

      vector < int > answer;

      int limit = meet[0].end;//ending time will be the limit
      answer.push_back(meet[0].pos);

      for (int i = 1; i < n; i++) {
          //check id starting time of new activity
          // s greater than or equal to ending tim of previous if yes then go ahead
         //we can start activity at same time as ending tme since there is only one party
         if (meet[i].start >= limit) //check on question basis on gfg > is right but on CN >= is used
         {
            limit = meet[i].end;//update the limit
            answer.push_back(meet[i].pos);
         }
      }
      cout<<"The order in which the meetings will be performed is "<<endl;
      for (int i = 0; i < answer.size(); i++) {
         cout << answer[i] << " ";
      }
      cout<<"no of activity :- "<<answer.size();
   }

};
int main() {
   Solution obj;
        #ifndef ONLINE_JUDGE    
       freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
       freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
     #endif
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   obj.maxactivitys(start, end, n);
   return 0;
}