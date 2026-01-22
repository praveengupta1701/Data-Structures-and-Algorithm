#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:

    int kth_Smallest_MinHeap(vector<int>&arr, int k) 
    {
        priority_queue<int>pq ;//MAX HEAP
        int n = arr.size()  ;

        for (int i = 0; i < arr.size(); i++) 
        {
            pq.push(arr[i])  ;
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
        // cout << "Kth Smallest element " << pq.top() << "\n"  ;
    }
  

} ;
int main() {

    vector<int>arr = {10, 12, 6, 14, 25, 30,67,90,86}  ;

    Solution obj ;
   int first= obj.kth_Smallest_MinHeap(arr, 3)  ;
   int second= obj.kth_Smallest_MinHeap(arr, 6)  ;
int sum=0;
   for (int i = 0; i < arr.size(); ++i)
   {
       /* code */
    if(arr[i]>first&&arr[i]<second)
    {
        sum=sum+arr[i];
        cout<<arr[i]<<" ";
    }
   }
   cout<<"\n"<<sum;

    return 0 ;
}
