#include<bits/stdc++.h>
using namespace std;


 vector < int > next(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n);
      stack < int > st;
      for (int i =  n - 1; i >= 0; i--) //for circular here it is i=2*n-1
      {
        while (!st.empty() && st.top() <= nums[i]) //for circular queue it's nums[i%n]
        {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
          else
          	nge[i] = -1;
        }
        st.push(nums[i]);//for circular queue it's nums[i%n]
      }
      return nge;
    }
int main(int argc, char const *argv[])
{
	vector<int> a{10,12,4,5,7,9,8,4,2,3,8};

	vector<int>  ans=next(a);
	 for_each(ans.begin(),ans.end(),[](int a){ cout<<a<<" ";});
	return 0;
}		

// OUTPUT
// 12 -1 5 7 9 -1 -1 8 3 8 -1

// for circular
// 12 -1 5 7 9 10 10 8 3 8 10