#include<bits/stdc++.h>
using namespace std;

vector<int>edges[100005];
vector<bool>vis(100005,false);
bool cycle;

void checkcycle(int src,int par)
{
    vis[src]=true;
    for(auto node:edges[src])
        if(!vis[node])
            checkcycle(node,src);
        else if(node!=par)
            cycle=true;
}

int main() 
{
    int n,m,u,v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cycle=false;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            checkcycle(i,-1);
    if(cycle)
        cout<<"There exists a cycle in this graph";
    else
        cout<<"There does not exists a cycle in this graph";
    return 0; 
}
