#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pi;

class Solution {

public:
 void top_frequency_number(vector<int>&arr, int k)
{
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
        priority_queue<pi, vector<pi>, greater<pi>>pq ;  //MIN HEAP
        int n = arr.size()  ;
       for (auto i = mp.begin(); i != mp.end(); i++) 
        {
            pq.push({i->second,i->first})  ;
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

    vector<int> arr = {6,1,1,4,4,5,3,2,2,8,10,9,4}  ;

    Solution obj ;
    obj.top_frequency_number(arr, 2 );

    return 0 ;
}
