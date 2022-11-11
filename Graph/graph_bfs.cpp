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

vector<int> bfs(int nodes,vector<int> adj[])
{
int vis[nodes]={0};
vis[0]=1;
queue<int> q;
q.push(0);
vector<int> bfs;
while(!q.empty())
{
	int node=q.front();
	q.pop();
	bfs.push_back(node);
	for(auto it:adj[node])
	{
		if(vis[it]==0)//neighbour nodes
		{
			vis[it]=1;
			q.push(it);//push if not visited
		}
	}
}
return bfs;
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