#include<bits/stdc++.h>
using namespace std;


 vector < int > next(vector < int > & nums) 
 {
      int n = nums.size();
      vector < int > nge;
      stack < int > s;
      for (int i =  n - 1; i >= 0; i--) //for circular here it is i=2*n-1
      {
        if(s.size()==0)
        {
          nge.push_back(-1);
        }
        else if(s.size()>0 && s.top() > nums[i])
        {
          nge.push_back(s.top());

        }
        else if(s.size()>0 && s.top() <= nums[i])
        {
           while (s.size() && s.top() <= nums[i]) //for circular queue it's nums[i%n]
          {
           s.pop();
          }

        if (s.size() ==0) 
        {
          nge.push_back(-1);
        }
        else
        {
          nge.push_back(s.top());
        }
      }
      s.push(nums[i]);//for circular queue it's nums[i%n]
    }
    reverse(nge.begin(),nge.end());
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