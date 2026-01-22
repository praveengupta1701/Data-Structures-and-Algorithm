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


//simple version
vector<long long> nextsmallestleft(vector<long long> a, int n)
    {
        vector<long long> ans;
        if(n==1)
        {   
            return ans;
        }
        stack<long long> s;
        //s.push(a[n-1]);
        for(int i=0;i<n;i++)//for circular here it is i=2*n-1
        {
            if(s.size()==0)
            {
                ans.push_back(-1);
                    cout<<"-1 a: ";
            }
            else if(s.size()>0 && s.top()<a[i])
            {
                ans.push_back(s.top());
                    cout<<s.top()<<" a: ";
               
            }
            else if(s.size()>0 && s.top()>=a[i])
            {
                while(s.size()>0 && s.top()>=a[i])//or circular queue it's nums[i%n]
                {
                    s.pop();
                }
                if(s.empty())
                {
                    ans.push_back(-1);

                }
                else 
                {
                    ans.push_back(s.top());
                    cout<<s.top()<<" a: ";
                }
            }
            s.push(a[i]);//for circular queue it's nums[i%n]
        }
        return ans;
 
    }

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
		}
		else if(s.size()>0&&s.top().first<nums[i])
		{
			v.push_back({s.top().first,s.top().second});
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
			}
			else
			{
				v.push_back({s.top().first,s.top().second});
			}
		}
		s.push({nums[i],i});
	}

	// cout<<"nsl index  \n";
	// for_each(v.begin(),v.end(),[](pair<int,int> x){cout<<x.first<<" "<<x.second<<" ";});

	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	v[i].second=i-v[i].second;
	// }
	return v;
}


int32_t main()
{   
	// #ifndef ONLINE_JUDGE    
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif

	vector<int> v={10,20,15,30,25,15,20};
	vector<long long> v1={10,20,15,30,25,1,20};

	vector<pair<int,int>> nsl_index;
	
	// vector<long long > ans1=nextsmallestleft(v1,7);
	// for(auto a:ans1)
	// {
	// 	cout<<a<<" ";
	// }


	cout<<endl;
	nsl_index=nsl(v);
	cout<<"nsl index  \n";

	for_each(nsl_index.begin(),nsl_index.end(),[](pair<int,int> x){cout/*<<x.first<<" "*/<<x.second<<" ";});
	// int ans=INT_MIN;
	// cout<<endl;
	// for(int i=1;i<=v.size()-1;i++)
	// {
	// 	ans=max(ans,abs(v[i]- nsl_index[i].first));
	// 		cout<<ans<<" --> ";
	// }



    return 0;
}