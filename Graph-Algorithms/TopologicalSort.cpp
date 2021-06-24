#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],int src,stack<int>&s,vector<bool>&vis) 
{
	vis[src]=true;
	for(auto node:adj[src])
		if(!vis[node])
			dfs(adj,node,s,vis);
    s.push(src);
}

void topologicalsort(vector<int>adj[],int n) 
{
	stack<int> s;
	vector<bool>vis(n+1,false);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(adj,i,s,vis);
	while(!s.empty())
	{
		cout<<s.top()<<' ';
		s.pop();
	}
	cout<<endl;
}

int main() 
{
	int n,m,u,v;
	cin>>n>>m;
	vector<int>adj[n+1];
	while(m--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	topologicalsort(adj,n);
	return 0;
}

/*
Input :
8 7
1 7
1 2
2 4
2 3
2 5
3 8
1 6
Output :
1 6 2 5 3 8 4 7 
*/
