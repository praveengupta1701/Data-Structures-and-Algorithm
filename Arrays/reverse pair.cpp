#include<bits/stdc++.h>

using namespace std;
int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2LL * nums[j]) 
      {// it will break out of loop if 2 half of array is finished or nums[i] isnot greater than 2* numns[j]
      j++;
    }
    total += (j - (mid + 1));// j-(mid+1) is no of elements on the left  because when j incease means num[i]>2*nums[j]
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

  if (low >= high) return 0;
  int mid = (low + high) / 2;
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);
  return inv;
}
int reversePairs(vector < int > & arr) {
  return MergeSort(arr, 0, arr.size() - 1);
}

int main() {
  vector<int> arr{1,3,2,3,1};
  cout << "The Total Reverse Pairs are " << reversePairs(arr);
}