#include<bits/stdc++.h>
using namespace std;

bool cost[100][100];
void warshall(int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				cost[j][k]=(cost[j][k]||(cost[j][i]&&cost[i][k]));
}

int main()
{
	int n,e,u,v;
	cin>>n>>e;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cost[i][j]=false;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		cost[u][v]=true;
		//cost[v][u]=true; uncomment this for bidirectional graph
	}
	warshall(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
			{
				if(cost[i][j])
					cout<<"Node "<<j<<" is reachable from node "<<i<<endl;
				else
					cout<<"Node "<<j<<" is not reachable from node "<<i<<endl;
			}
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
Node 1 is reachable from node 0
Node 2 is reachable from node 0
Node 3 is reachable from node 0
Node 4 is reachable from node 0
Node 5 is not reachable from node 0
Node 0 is reachable from node 1
Node 2 is reachable from node 1
Node 3 is reachable from node 1
Node 4 is reachable from node 1
Node 5 is not reachable from node 1
Node 0 is reachable from node 2
Node 1 is reachable from node 2
Node 3 is reachable from node 2
Node 4 is reachable from node 2
Node 5 is not reachable from node 2
Node 0 is reachable from node 3
Node 1 is reachable from node 3
Node 2 is reachable from node 3
Node 4 is reachable from node 3
Node 5 is not reachable from node 3
Node 0 is reachable from node 4
Node 1 is reachable from node 4
Node 2 is reachable from node 4
Node 3 is reachable from node 4
Node 5 is not reachable from node 4
Node 0 is reachable from node 5
Node 1 is reachable from node 5
Node 2 is reachable from node 5
Node 3 is reachable from node 5
Node 4 is reachable from node 5
*/