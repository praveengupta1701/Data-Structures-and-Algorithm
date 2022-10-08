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

vector<pair<int,int>> ngl(vector<int>& nums)
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
		else if(s.size()>0&&s.top().first>nums[i])
		{
			v.push_back({s.top().first,s.top().second});
		}
		else if(s.size()>0&&s.top().first<=nums[i])
		{
			while(s.size()>0&&s.top().first<=nums[i]) {
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

	cout<<"ngl index  \n";
	for_each(v.begin(),v.end(),[](pair<int,int> x){cout<<x.first<<" "<<x.second<<" ";});

	for (int i = 0; i < v.size(); ++i)
	{
		v[i].second=i-v[i].second;
	}
	return v;
}


int32_t main()
{   
	#ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> v={100,80,60,70,60,75,85};
	vector<pair<int,int>> ngl_index;
	ngl_index=ngl(v);


	cout<<endl;
	for_each(ngl_index.begin(),ngl_index.end(),[](pair<int,int> x){cout<<x.first<<" "<<x.second<<" ";});
	int ans=INT_MIN;
	cout<<endl;
	for(int i=1;i<=v.size()-1;i++)
	{
		ans=max(ans,abs(v[i]- ngl_index[i].first));
			cout<<ans<<" --> ";
	}



    return 0;
}