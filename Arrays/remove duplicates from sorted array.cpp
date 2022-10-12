#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(int arr[], int n)//t(n)=n// two pointer approch
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
int setremoveDuplicates(int arr[], int n)//t(n)=0(nlogn + n)
 {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}
int mapremoveDuplicates(vector<int>& nums) 
{
vector<int> no_dup;// The array that we will set nums equal to upon completion
unordered_map<int, int> occ; // The amount of times the integer occurs within the array
for (int& n : nums)
 { // Standard way of iterating through a vector
  if (occ[n] < 1)
   { // If there are less than 1 occurences of this integer n
    no_dup.push_back(n); // Push the integer back to the new array
    }
    occ[n]++; // Increment the number of occurences of this certain integer n
 }
nums = no_dup; // Set the parameter vector equal to the new vector we have created
return no_dup.size(); // Return the size of the vector (k = no_dup.size()  unordered_map<int,int> n;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}