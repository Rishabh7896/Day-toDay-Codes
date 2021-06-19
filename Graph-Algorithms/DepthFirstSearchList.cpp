#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100];
vector<int>visited(100);
void dfs(int n,int source)
{
	cout<<source<<" ";
	visited[source]=true;
	for(int i:graph[source])
		if(!visited[i])
			dfs(n,i);
}

int main()
{
	int n,e,u,v;
	cin>>n>>e;
	for(int i=0;i<n;i++)
	{
		graph[i].clear();
		visited[i]=false;
	}
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		//graph[v].push_back(u); uncomment this for bidirectional graph
	}
	int source;
	cin>>source;
	cout<<"DFS Traversal from node "<<source<<" is: ";
	dfs(n,source);
}

/*
Sample Input:
6 11
5 3
3 4
4 3
3 1
1 4
2 3
1 2
0 2
2 0
0 1
0 4
5 0

Sample Output:
BFS Traversal from node 5 is: 5 3 1 4 2 0 
*/
