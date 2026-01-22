#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:

    void kth_Largest_Elements(vector<int>&arr, int k)
{

        priority_queue<int, vector<int>, greater<int>>pq ;  //MIN HEAP
        int n = arr.size()  ;

       for (int i = 0; i < arr.size(); i++) 
        {
            pq.push(arr[i])  ;
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
         cout << "Kth Largest elements " ;
        while(pq.size()>0)
        {   
            cout<<pq.top() << " "  ;
            pq.pop();
        }
}


} ;
int main() {

    vector<int>arr = {1, 2, 6, 4, 5, 3}  ;

    Solution obj ;
    obj.kth_Largest_Elements(arr, 3)  ;

    return 0 ;
}
