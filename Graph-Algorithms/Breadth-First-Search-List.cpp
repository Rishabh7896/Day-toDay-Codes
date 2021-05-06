#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100];
void bfs(int n,int source)
{
	vector<bool>visited(n,false);
	queue<int>q;
	q.push(source);
	visited[source]=true;
	while(!q.empty())
	{
		source=q.front();
		q.pop();
		cout<<source<<" ";
		for(int i:graph[source])
			if(!visited[i])
			{
				q.push(i);
				visited[i]=true;
			}
	}
}

int main()
{
	int n,e,u,v;
	cin>>n>>e;
	for(int i=0;i<n;i++)
		graph[i].clear();
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		//graph[v].push_back(u); uncomment this for bidirectional graph
	}
	int source;
	cin>>source;
	cout<<"BFS Traversal from node "<<source<<" is: ";
	bfs(n,source);
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
BFS Traversal from node 5 is: 5 3 4 1 2 0 
*/