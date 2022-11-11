// Created by ...
/* Author -Praveen Gupta*/

#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <memory>
#include <condition_variable>
using namespace std;
using namespace std::chrono;


class Solution {
public:
       string convert(string s, int m) 
    {
        int n=s.size();
        vector<vector<char>> v(m, vector<char>(m));
        int k=1;
        int l=0;
        while(l<n)
        {
                for(int i=0;i<m&&l<n;i++,l++)
                {
                    v[i].push_back(s[l]);
                   // cout<<s[l]<<" 1 ";
                } 
            //cout<<" \n";
                for(int i=m-2;i>=1&&l<n;i--,l++)
               {
                    v[i].push_back(s[l]);
                   // cout<<s[l]<<" 2 ";
                } 
        }
           string ans="";
        for(auto i=0;i<m;i++)
        {
            int x=v[i].size();
            for(int y=0;y<x;y++)
            {
               cout<<v[i][y]<<" ";
                if((v[i][y]>='A'&&v[i][y]<='Z')||(v[i][y]>='a'&&v[i][y]<='z')||(v[i][y]==',')||(v[i][y]=='.'))
                ans+=v[i][y];
            }
        }
        return ans;
        
    }
};

int32_t main()
{   
    /* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/

    Solution a;
    string s="hello",ans="";
    int k=2;
    ans=a.convert(s,k);
    cout<<ans;

    return 0;
}