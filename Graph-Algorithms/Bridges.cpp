#include<bits/stdc++.h> 
using namespace std;

vector<int>graph[100001];  
bool vis[100001];
int in[100001],low[100001];
int timer=1;  

void dfs(int source,int parent)
{
    vis[source]=true;
    in[source]=low[source]=timer;
    timer++;
    for(auto child:graph[source])
    {
        if(parent==child) 
            continue;
        if(vis[child]==true)
            low[source]=min(low[source],in[child]);
        else
        {
            dfs(child,source);
            if(low[child]>in[source])
                cout<<source<<"-"<<child<<" is a bridge\n";
            low[source]=min(low[source],low[child]);
        }
    }
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
    return 0; 
}

/*
Input:
First line contains two space separated integers,(n,m) 
n- no of vertices, m- no of edges.
Then m lines follow, each line has 2 space separated integers ui ,vi which denotes edge between vertex ui to vi.


TEST CASE
4 4
1 2
2 3
2 4
3 4

OUTPUT
1-2 is a bridge

Time- complexity: O(n+m)

Space Complexity: O(n)

*/

