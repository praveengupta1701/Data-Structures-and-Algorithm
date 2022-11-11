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

void dfshelper(int node, vector<int>  adj[],int vis[],vector<int> &ls)
{
	vis[node]=1;
	ls.push_back(node);
	//traverse all its neighbour
	for(auto it:adj[node])
	{
		if(vis[it]==0)//neighbour nodes
		{
			dfshelper(it,adj,vis,ls);
		}
	}
}
vector<int> dfs(int nodes,vector<int> adj[])
{
int vis[nodes]={0};
int start=0;
vector<int> ls;
dfshelper(start,adj,vis,ls);
return ls;
}

// Space--3O(n)
// Time--O(n)+O(2E)(degree)

int32_t main()
{   
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/



    return 0;
}