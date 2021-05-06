#include<bits/stdc++.h>
using namespace std;

int cost[100][100];
int dist[100],path[100];

bool allvisited(vector<bool>vis,int n)
{
    for(int i=0;i<n;i++)
        if(!vis[i])
            return false;
    return true;
}

void dijkstra(int source,int n)
{
	vector<bool>vis(n,false);
	for(int i=0;i<n;i++)
	{
		dist[i]=cost[source][i];
		path[i]=source;
	}
	vis[source]=true;
	while(!allvisited(vis,n))
	{
		int newdist=INT_MAX;
		for(int i=0;i<n;i++)
			if(!vis[i] && newdist>dist[i])
			{
				newdist=dist[i];
				source=i;
			}
		vis[source]=true;
		for(int i=0;i<n;i++)
			if(!vis[i] && dist[i]>newdist+cost[source][i])
			{
				dist[i]=newdist+cost[source][i];
				path[i]=source;
			}
	}
}

int main()
{
	int n,e,u,v,w;
	cin>>n>>e;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cost[i][j]=(i==j?0:9999);
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		cost[u][v]=w;
	}
	int source,destination;
	cin>>source>>destination;
	dijkstra(source,n);
	cout<<"Minimum Distance from "<<source<<" to "<<destination<<": "<<dist[destination];
	cout<<endl<<"Path from "<<source<<" to "<<destination<<": "; 
	stack<int>st;
	while(destination!=source)
	{
		st.push(destination);
		destination=path[destination];
	}
	st.push(destination);
	//path from source to destination
	while(st.size()>1)
	{
		cout<<st.top()<<"->";
		st.pop();
	}
	cout<<st.top()<<endl;
}

/*
Sample Input:
6 11
5 3 4
3 4 35
4 3 30
3 1 10 
1 4 20
2 3 20
1 2 15
0 2 10
2 0 20
0 1 15
0 4 45
5 0

Sample Output:
Minimum Distance from 5 to 0: 49
Path from 5 to 0: 5->3->1->2->0
*/