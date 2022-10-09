#include <bits/stdc++.h>

using namespace std;
vector < int > majorityElement(int nums[], int n) {
  
        int sz = n;
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
//checking two highest element coming in array amoungst others
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = nums[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = nums[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
        
// utill now num1 and num2 are two which is highest coming in array amoungst others
  vector < int > ans;
  count1 = count2 = 0;
        
// now recounting for precaution of num1 and num2
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }
// whoever count is greater than from n/3 between num1 and num2 will be returned
  // if both are greather then bth will be pushed
  if (count1 > sz / 3)
    ans.push_back(num1);
  if (count2 > sz / 3)
    ans.push_back(num2);
  return ans;
}

int main() {
  int arr[] = {1,2,2,3,2};
  vector < int > majority;
  majority = majorityElement(arr, 5);
  cout << "The majority element is ";

  for (auto it: majority) {
    cout << it << " ";
  }
}