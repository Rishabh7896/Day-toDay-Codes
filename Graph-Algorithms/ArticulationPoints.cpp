#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100001];
bool vis[100001];
int in[100001],low[100001];
int timer=1;

set<int>vertices;

void dfs(int source,int parent) 
{
	vis[source]=true;
	in[source]=low[source]=timer;
	timer++;
	int children=0;
	for(auto child:graph[source]) 
	{
		if(parent==child) 
			continue;
		if(vis[child]==true)
			low[source]=min(low[source],in[child]);
		else 
		{
			dfs(child,source);
			low[source]=min(low[source],low[child]);
			if(low[child]>=in[source] && parent!=-1)
				vertices.insert(source);
			children++;
		}
	}
	if(parent==-1 && children>1)
		vertices.insert(source);
}

int main() 
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		vis[i]=false;

	for(int i=1;i<=n;i++)
		if(!vis[i]) 
			dfs(i,-1);
	for(auto val:vertices)
		cout<<val<<" ";
	return 0;
}

/*
Sample Input:
5 5
1 2
1 3
2 3
3 4
4 5
Sample Output:
3 4
*/
