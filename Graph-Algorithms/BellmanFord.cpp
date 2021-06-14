#include <bits/stdc++.h>
using namespace std;

typedef struct edg
{
    int x,y,w;
}EDGE;

void BellmanFord(int n,int e,vector<EDGE>edges,int src)
{
    int dist[n+1];
    for(int i=0;i<=n;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    for(int i=1;i<n;i++)
        for(int j=0;j<e;j++)
            if(dist[edges[j].x]!=INT_MAX && dist[edges[j].x]+edges[j].w<dist[edges[j].y])
                dist[edges[j].y]=dist[edges[j].x]+edges[j].w;
    for(int i=0;i<e;i++)
        if(dist[edges[i].x]!=INT_MAX && dist[edges[i].x]+edges[i].w<dist[edges[i].y]) 
        {
            cout<<"Graph contains negative weight cycle"<<endl;
            return;
        }
    for(int i=1;i<=n;i++)
        cout<<"Distance of "<<i<<" from "<<src<<" is: "<<dist[i]<<endl;
    return;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<EDGE>edges(e);
    for(int i=0;i<e;i++)
        cin>>edges[i].x>>edges[i].y>>edges[i].w;
    int src;
    cin>>src;
    BellmanFord(n,e,edges,src);
    return 0;
}
