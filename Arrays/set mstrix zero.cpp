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


int32_t main()
{   
	     #ifndef ONLINE_JUDGE    
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	    #endif

    int a[5][4]={{1,0,0,1},{1,1,1,1},{1,1,1,0},{1,0,1,1},{1,1,1,0}};
   cin>>k;
   int k=4;//rows
   int x=4;//columns
        cout<<k<<" "<<x;
            vector<int> d1(k,-1),d2(x,-1);
         for (int i = 0; i < k; ++i)
    {
    	/* code */
    	for (int j = 0; j < x; ++j)
    	{
    		/* code */
    		if(a[i][j]==0)
    		{
    			d1[i]=0;
    			d2[j]=0;
    		}
    	}
    }

   for (int i = 0; i < k; ++i)
    {
    	/* code */
    	for (int j = 0; j < x; ++j)
    	{
    		if(d1[i]==0||d2[j]==0)
    		{
    			a[i][j]=0;
    		}
    	}
    }
    return 0;
}