#include<bits/stdc++.h>
using namespace std;

vector<int>adj[10009];
int visited[10009];

void dfs(int node)
{
    visited[node]=1;
    for(auto child:adj[node])
        if(visited[child]==0)
            dfs(child);
}

int get_connected_components(int nodes)
{
    int connected_components=0;
    for(int i=1;i<=nodes;i++)
        if(visited[i]==0)
        {
            dfs(i);
            connected_components++;
        }
    return connected_components;
}

int main()
{
    int nodes,edges,u,v;
    cin>>nodes>>edges;
    for(int i=1;i<=edges;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    cout<<get_connected_components(nodes)<<endl;
}

/*
Standard Input:
8 5
1 2
2 3
2 4
3 5
6 7
Sample Output:
3
*/
