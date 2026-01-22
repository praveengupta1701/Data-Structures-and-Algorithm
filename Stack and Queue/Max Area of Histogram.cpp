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

vector<pair<int,int>> nsl(vector<int>& nums)
{
    stack<pair<int,int>> s;
    int n=nums.size();
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (s.size()==0)
        {
            /* code */
            v.push_back({i,-1});
            cout<<"0 ";
        }
        else if(s.size()>0&&s.top().first<nums[i])
        {
            v.push_back({s.top().first,s.top().second});
                cout<<s.top().second<<" ";

        }
        else if(s.size()>0&&s.top().first>=nums[i])
        {
            while(s.size()>0&&s.top().first>=nums[i]) {
                /* code */
                s.pop();
            }
            if(s.size()==0)
            {
                v.push_back({i,-1});
            cout<<"0 ";

            }
            else
            {
                v.push_back({s.top().first,s.top().second});
                cout<<s.top().second<<" ";
            }
        }
        s.push({nums[i],i});
    }
    cout<<"\n";

    // cout<<"ngl index  \n";
    // for_each(v.begin(),v.end(),[](pair<int,int> x){cout<<x.first<<" "<<x.second<<" ";});

    // for (int i = 0; i < v.size(); ++i)
    // {
    //     v[i].second=i-v[i].second;
    // }
    return v;
}

vector<pair<int,int>> nsr(vector<int>& nums)
{
    stack<pair<int,int>> s;
    int n=nums.size();
    vector<pair<int,int>> v;
    for (int i = n-1; i >=0; i--)
    {
        /* code */
        if (s.size()==0)
        {
            /* code */
            v.push_back({i,n});
                cout<<n<<" ";
        }
        else if(s.size()>0&&s.top().first<nums[i])
        {
            v.push_back({s.top().first,s.top().second});
            cout<<s.top().second<<" ";
        }
        else if(s.size()>0&&s.top().first>=nums[i])
        {
            while(s.size()>0&&s.top().first>=nums[i]) {
                /* code */
                s.pop();
            }
            if(s.size()==0)
            {
                v.push_back({i,n});
                cout<<n<<" ";

            }
            else
            {
                v.push_back({s.top().first,s.top().second});
                cout<<s.top().second<<" ";

            }
        }
        s.push({nums[i],i});
    }

cout<<"\n";
  reverse(v.begin(),v.end());

    // cout<<"ngl index  \n";
    // for_each(v.begin(),v.end(),[](pair<int,int> x){cout<<x.first<<" "<<x.second<<" ";});

    // for (int i = 0; i < v.size(); ++i)
    // {
    //     v[i].second=i-v[i].second;
    // }
    return v;
}

void Max_Area_Hiatogram(vector<int> v)
{
    vector<pair<int,int>> left,right;
    left=nsl(v);
    right=nsr(v);
    int n=v.size();

    vector<int> area(n),width(n);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        width[i]=right[i].second-left[i].second-1;
        area[i]=v[i]*width[i];
        cout<<area[i]<<" ";
        maxi=max(maxi,area[i]);
    }
    cout<<endl;
    cout<<maxi;

}



int32_t main()
{   
    // #ifndef ONLINE_JUDGE    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    vector<int> v={2,3,3,2};
    // vector<pair<int,int>> ngl_index;
    // ngl_index=ngl(v);
    Max_Area_Hiatogram(v);

    // vector<int> ans=StockSpanProblem(v);
    
     // for_each(ans.begin(),ans.end(),[](int x){cout<<x<<" ";});



    // cout<<endl;
    // for_each(ngl_index.begin(),ngl_index.end(),[](pair<int,int> x){cout<<x.first<<" "<<x.second<<" ";});
    // int ans=INT_MIN;
    // cout<<endl;
    // for(int i=1;i<=v.size()-1;i++)
    // {
    //     ans=max(ans,abs(v[i]- ngl_index[i].first));
    //         cout<<ans<<" --> ";
    // }



    return 0;
}