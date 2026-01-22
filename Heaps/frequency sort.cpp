#include <bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pi;

class Solution {

public:
 void frequency_sort(vector<int>&arr)
{
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[arr[i]]++;
    }
        priority_queue<pi>pq ;  //MAX HEAP
        int n = arr.size()  ;
       for (auto i = mp.begin(); i != mp.end(); i++) 
        {
            pq.push({i->second,i->first})  ;
        }
        while(pq.size()>0)
        {   
            int fre=pq.top().first;
            int value=pq.top().second;
            for (int i = 0; i < fre; ++i)
            {
                cout<<value<<" ";
            }
            pq.pop();
        }
}


} ;
int main() {

    vector<int> arr = {6,1,1,4,4,5,3,2,2,8,10,9,4}  ;

    Solution obj ;
    obj.frequency_sort(arr);

    return 0 ;
}
