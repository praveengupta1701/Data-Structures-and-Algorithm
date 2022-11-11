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
	/* #ifndef ONLINE_JUDGE    
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\input.txt", "r", stdin);
    freopen("C:\\Users\\Praveen\\Documents\\programs\\cpp\\output.txt", "w", stdout);
  #endif*/

	int n,m;
	cin>>n>>m;
	//adjency matrix;
	/*int adj[n+1][m+1];
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u][v];
		adj[v][u];//space o(n*n)

		//for weighted graph for matrix
		adj[u][v]=wt;
		adj[v][u]=wt;//space o(n*n)
	}

	//adjency list for undirected
	vector<int> adjlist[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	//adjency list for directed
	vector<int> adjlist1[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		//edge b/w u--->v
		cin>>u>>v;
		adjlist1[u].push_back(v);//space==O(E)
	}
*/
	// for weighted graph in list
	vector<pair<int,int>> adjlistwt[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		adjlistwt[u].push_back({v,wt});
		adjlistwt[v].push_back({u,wt});
	}

    return 0;
}