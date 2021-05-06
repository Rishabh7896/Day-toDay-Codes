#include<bits/stdc++.h>
using namespace std;

int cost[100][100];
void floyds(int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);
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
		//cost[v][u]=w; uncomment this for bidirectional graph
	}
	floyds(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
			{
				cout<<"Minimum Distance from "<<i<<" to "<<j<<" is: ";
				if(cost[i][j]==9999)
					cout<<"Infinity"<<endl;
				else
					cout<<cost[i][j]<<endl;
			}
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
Minimum Distance from 0 to 1 is: 15
Minimum Distance from 0 to 2 is: 10
Minimum Distance from 0 to 3 is: 30
Minimum Distance from 0 to 4 is: 35
Minimum Distance from 0 to 5 is: Infinity
Minimum Distance from 1 to 0 is: 35
Minimum Distance from 1 to 2 is: 15
Minimum Distance from 1 to 3 is: 35
Minimum Distance from 1 to 4 is: 20
Minimum Distance from 1 to 5 is: Infinity
Minimum Distance from 2 to 0 is: 20
Minimum Distance from 2 to 1 is: 30
Minimum Distance from 2 to 3 is: 20
Minimum Distance from 2 to 4 is: 50
Minimum Distance from 2 to 5 is: Infinity
Minimum Distance from 3 to 0 is: 45
Minimum Distance from 3 to 1 is: 10
Minimum Distance from 3 to 2 is: 25
Minimum Distance from 3 to 4 is: 30
Minimum Distance from 3 to 5 is: Infinity
Minimum Distance from 4 to 0 is: 75
Minimum Distance from 4 to 1 is: 40
Minimum Distance from 4 to 2 is: 55
Minimum Distance from 4 to 3 is: 30
Minimum Distance from 4 to 5 is: Infinity
Minimum Distance from 5 to 0 is: 49
Minimum Distance from 5 to 1 is: 14
Minimum Distance from 5 to 2 is: 29
Minimum Distance from 5 to 3 is: 4
Minimum Distance from 5 to 4 is: 34
*/