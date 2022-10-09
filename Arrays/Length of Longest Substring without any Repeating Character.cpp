#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) //iterate till last index

      {
        if (mpp[s[right]] != -1)// character at right index exist or not
          left = max(mpp[s[right]] + 1, left);// right is not updated unless it os greaterbthen left

        mpp[s[right]] = right;//update last visied elementin hash map

        len = max(len, right - left + 1);// lenght of substring (r-l+1)
        right++; // right to next index
      }
      return len;
    }

    int lengthOfLongestSubstring_op(string s) {
        // may also use a map
        vector<int> mp(256,0);
        int n = s.length(); 
        int ans = 0;
        //loop through the string
        for(int i = 0, start = i; i < n;i++)
        {
            // the start value will be updated based on our current letter and wether it has been seen before
            /*
                for example:
                    a b c a b
                    
             start: 0 0 0 1 2 
             
             so as we encouter letters we've already seen, start is updated to be the last place we saw those letters,
             only if that last position is greater than start.
            
             because of something like:
                a b b a
                0 0 2 1
                
                we don't want to update start to 1 because it would then include 2 b's.
            */
            start = max(start,mp[s[i]]);
            
            // updates answer 
            ans = max(ans, (i - start + 1));
            
            
            // reset the most recent position of the character 
            mp[s[i]] = i+1;
        }
        return ans;
    }
};


int main() {
  string str = "takeUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}