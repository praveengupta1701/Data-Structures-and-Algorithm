#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:
 std::vector<int> sort_k_sorted(vector<int>&arr, int k)
{

        priority_queue<int, vector<int>, greater<int>>pq ;  //MIN HEAP
        int n = arr.size()  ;
        std::vector<int> v;
       for (int i = 0; i < arr.size(); i++) 
        {
            pq.push(arr[i])  ;
            if(pq.size()>k)
            {
                v.push_back(pq.top());
                pq.pop();
            }
        }
        while(pq.size()>0)
        {   
            v.push_back(pq.top());
            pq.pop();
        }
         cout << "Sort vector " ;
         for(auto i:v)
         {
            cout<<i<<" ";
         }
         return v;
}


} ;
int main() {

    vector<int>arr = {6,5,3,2,8,10,9}  ;

    Solution obj ;
    std::vector<int> v= obj.sort_k_sorted(arr, 3)  ;

    return 0 ;
}
