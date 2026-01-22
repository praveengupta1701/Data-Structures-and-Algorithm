#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:
 void k_closest(vector<int>&arr, int k,int x)
{

        priority_queue<pair<int,int>>pq ;  
        int n = arr.size()  ;
       for (int i = 0; i < arr.size(); i++) 
        {
            pq.push({abs(arr[i]-x),arr[i]})  ;
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(pq.size()>0)
        {   
            cout<<pq.top().second<<" ";
            pq.pop();
        }
}


} ;
int main() {

    vector<int>arr = {6,5,3,2,8,10,9,4}  ;

    Solution obj ;
    obj.k_closest(arr, 3,6)  ;

    return 0 ;
}
