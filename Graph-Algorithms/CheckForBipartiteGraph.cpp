#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>graph[],int src,int visited[],int parentOf[],int color) 
{

	visited[src]=color;
	for(int nbr:graph[src]) 
	{
		if(!visited[nbr]) 
		{
			parentOf[nbr]=src;
			bool oddLenCycleFound=dfs(graph,nbr,visited,parentOf,3-color);
			if(oddLenCycleFound) 
				return 0;
		} 
		else 
		{
			if(parentOf[src]==nbr);
			else
				if(visited[nbr]==color) 
					return 0;
		}
	}
	return true;
}

bool isbipartite(vector<int> graph[],int n) 
{

	int visited[n]={0};
	int parentOf[n];
	for(int i=0;i<n;i++)
		parentOf[i]=i;
	bool ans=dfs(graph,0,visited,parentOf,1);
	for (int i = 0; i < n; i++)
		cout<<i<<" color: "<<visited[i]<<endl;
	return ans;
}

int main() 
{
	int n,m,u,v;
	cin>>n>>m;
	vector<int>graph[n];

	for(int i=0;i<m;i++) 
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout<<isbipartite(graph,n);
}

/*
Input:
5 5
0 1
1 2
2 3
3 4
4 0

Output:
0 color=1
1 color=2
2 color=1
3 color=2
4 color=1
0
*/
