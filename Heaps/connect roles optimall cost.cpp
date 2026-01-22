#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pi;

class Solution {

public:
 void connect_ropes(vector<int>&arr)
{
    
        priority_queue<int, vector<int>, greater<int>>pq ;  //MIN HEAP

        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
        }
        int total=0;
        int n = arr.size()  ;
        while(pq.size()>=2)
        {   
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            int cost=first+second;
            total=total+cost;
            pq.push(cost);
        }
        cout<<total<<" ";
}


} ;
int main() {

    vector<int> arr = {1,2,3,4,5}  ;

    Solution obj ;
    obj.connect_ropes(arr );

    return 0 ;
}
