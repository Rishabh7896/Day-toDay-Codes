#include<bits/stdc++.h>
using namespace std;

// minimize the maximum weight in the path from a to b
typedef struct edg
{
    int x,y,w;
}EDGE;

bool comp(const EDGE &e1,const EDGE &e2)
{
    return e1.w<e2.w;
}

int findParent(int x,vector<int>&par)
{
    while(par[x]!=x)
    {
        //optimization
        par[x]=par[par[x]];
        x=par[x];
    }
    return x;
}
void unio(int x,int y,vector<int>&par,vector<int>&ran)
{
    if(ran[x]>ran[y])
        par[y]=x;
    else if(ran[y]>ran[x])
        par[x]=y;
    else
    {
        par[x]=y;
        ran[y]+=1;
    }
}
void dfs(vector<pair<int,int>>adj[],vector<bool>&vis,int src,int dest,int &ans,int curcost)
{
    vis[src]=true;
    if(src==dest)
    {
        ans=min(ans,curcost);
        return;
    }
    for(auto [node,cost]:adj[src])
        if(!vis[node])
        {
            dfs(adj,vis,node,dest,ans,max(curcost,cost));
        }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<EDGE>edges(e);
    for(int i=0;i<e;i++)
        cin>>edges[i].x>>edges[i].y>>edges[i].w;
    sort(edges.begin(),edges.end(),comp);
    vector<int>par(n+1),ran(n+1);
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        ran[i]=0;
    }
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<e;i++)
    {
        int u=findParent(edges[i].x,par);
        int v=findParent(edges[i].y,par);
        if(u!=v)
        {
            unio(u,v,par,ran);
            adj[edges[i].x].push_back({edges[i].y,edges[i].w});
            adj[edges[i].y].push_back({edges[i].x,edges[i].w});
        }
    }
    int ans=INT_MAX;
    vector<bool>vis(n+1,false);
    dfs(adj,vis,1,n,ans,INT_MIN);
    cout<<ans;
    return 0;
}


/*
Input:
6 6
1 2 1
2 3 6
3 6 1
1 4 2
4 5 2
5 6 4

Output:
4
*/
