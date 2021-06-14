#include<bits/stdc++.h>
using namespace std;

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
int main()
{
    int n,e;
    cin>>n>>e;
    vector<EDGE>edges(e);
    for(int i=0;i<e;i++)
        cin>>edges[i].x>>edges[i].y>>edges[i].w;
    sort(edges.begin(),edges.end(),comp);
    int weight=0;
    vector<int>par(n+1),ran(n+1);
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        ran[i]=0;
    }
    cout<<"Edge \tWeight\n"; 
    for(int i=0;i<e;i++)
    {
        int u=findParent(edges[i].x,par);
        int v=findParent(edges[i].y,par);
        if(u!=v)
        {
            unio(u,v,par,ran);
            weight+=edges[i].w;
            cout<<edges[i].x<<" - "<<edges[i].y<<" \t"<<edges[i].w<<" \n"; 
        }
    }
    cout<<"Weight of minimum spanning tree: "<<weight;
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
7 - 8   1 
6 - 7   2 
3 - 9   2 
1 - 2   4 
3 - 6   4 
3 - 4   7 
2 - 3   8 
4 - 5   9 
Weight of minimum spanning tree: 37
*/