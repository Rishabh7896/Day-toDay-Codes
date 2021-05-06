#include<bits/stdc++.h>
using namespace std;

bool graph[100][100];
vector<int>visited(100);
void dfs(int n,int source)
{
	visited[source]=true;
	cout<<source<<" ";
	for(int i=0;i<n;i++)
		if(!visited[i] && graph[source][i])
			dfs(n,i);
}

int main()
{
	int n,e,u,v;
	cin>>n>>e;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			graph[i][j]=false;
		visited[i]=false;
	}
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		graph[u][v]=true;
		//graph[v][u]=true; uncomment this for bidirectional graph
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
BFS Traversal from node 5 is: 5 3 1 2 0 4 
*/