#include <bits/stdc++.h>
using namespace std ;

class Solution {

public:
void swap_sort(vector<int>&arr)  //  O(n)
{
//preprocessing
int i=0;
while(i<arr.size())
{
    if(arr[i]!=arr[arr[i]-1])
    {
        swap(arr[i],arr[arr[i]-1]);
    }
    else
    {
        i++;
    }
}
}

void missing_duplicates(vector<int>&arr)
{
    swap_sort(arr);
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=i+1)
        {
            int miss=i+1;
            int dup=arr[i];
            cout<<"missing : "<<miss<<" Duplicate : "<<dup<<" \n";
        }
    }
}


} ;
int main() {

    vector<int>arr = {1,5,3,2,1,5 ,3,8,7,3}  ;

    Solution obj ;
    obj.missing_duplicates(arr)  ;

    return 0 ;
}
