//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    
long long int merge(long long int arr[],long long int temp[],long long int left,long long int mid,long long int right)
{
    long long int inv_count=0;
    long long int i = left;
    long long int j = mid;
    long long int k = left;
    while((i <= mid-1) && (j <= right))
    {
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

long long int merge_Sort(long long int arr[],long long int temp[],long long int left,long long int right)
{
    long long int mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
    long long int inversionCount(long long int arr[], long long int N)
    {
        // Your Code Here
        long long int temp[N];
        long long int ans;
        ans=merge_Sort(arr,temp,0,N-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
         #ifndef ONLINE_JUDGE    
        freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
        freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
      #endif
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends