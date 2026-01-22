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
vector<long long> nextsmallestright(vector<long long> a, int n)
    {
        vector<long long> ans;
        if(n==1)
        {   
            return ans;
        }
        stack<long long> s;
        //s.push(a[n-1]);
        for(int i=n-1;i>=0;i--)//for circular here it is i=2*n-1
        {
            if(s.size()==0)
            {
                ans.push_back(-1);// we are taking n as we are assumming that nth element is the smallent one
                    // cout<<n<<" a: ";
            }
            else if(s.size()>0 && s.top()<a[i])
            {
                ans.push_back(s.top());
                    // cout<<s.top()<<" a: ";
               
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
                    // cout<<n<<" a: ";

                }
                else 
                {
                    ans.push_back(s.top());
                    // cout<<s.top()<<" a: ";
                }
            }
            s.push(a[i]);//for circular queue it's nums[i%n]
        }
         reverse(ans.begin(),ans.end());
        return ans;
 
    }

vector<pair<int,int>> nsr(vector<int>& nums)
{
	stack<pair<int,int>> s;
	int n=nums.size();
	vector<pair<int,int>> v;
	 for(int i=n-1;i>=0;i--)
	{
		/* code */
		if (s.size()==0)
		{
			/* code */
			v.push_back({i,n});// we are taking n as we are assumming that nth element is the smallent one
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
				v.push_back({i,n});// we are taking n as we are assumming that nth element is the smallent one
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
  reverse(v.begin(),v.end());
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
	vector<long long> v1={4,5,2,10,8};

	vector<pair<int,int>> nsl_index;
	
	vector<long long > ans1=nextsmallestright(v1,5);
	// for(auto a:ans1)
	// {
	// 	cout<<a<<" ";
	// }


	// cout<<endl;
	nsl_index=nsr(v);
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