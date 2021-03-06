#include <bits/stdc++.h>
using namespace std;

int minKey(int n,int key[],bool mstSet[])
{
	int min=INT_MAX,min_index;
	for(int v=1;v<=n;v++)
		if(mstSet[v]==false && key[v]<min)
		{
			min=key[v];
			min_index=v;
		}
	return min_index;
}
void prims(int n,vector<vector<int>>graph)
{
	int parent[n+1],key[n+1];
	bool mstSet[n+1];
	for(int i=1;i<=n;i++)
	{
		key[i]=INT_MAX;
		mstSet[i]=false;
	}
	key[1]=1;
	parent[1]=-1;
	int weight=0;
	for(int i=1;i<n;i++)
	{
		int u=minKey(n,key,mstSet);
		mstSet[u]=true;
		for(int v=1;v<=n;v++)
			if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
			{
				parent[v]=u;
				key[v]=graph[u][v];
			}
	}
	cout<<"Edge \tWeight\n"; 
    for(int i=2;i<=n;i++) 
    {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
        weight+=graph[i][parent[i]];
    }
    cout<<"Weight of minimum spanning tree: "<<weight;
}
int main()
{
	int n,e,u,v,w;
	cin>>n>>e;
	vector<vector<int>>graph(n+1,vector<int>(n+1,0));
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		graph[u][v]=w;
		graph[v][u]=w;
	}
	prims(n,graph);
	return 0;
}

/*
Sample Input:
9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
2 8 11
8 9 7
9 7 6 
3 9 2
3 6 4
4 6 14
Sample Output:
Edge    Weight
1 - 2   4 
2 - 3   8 
3 - 4   7 
4 - 5   9 
3 - 6   4 
6 - 7   2 
7 - 8   1 
3 - 9   2 
Weight of minimum spanning tree: 37
*/
