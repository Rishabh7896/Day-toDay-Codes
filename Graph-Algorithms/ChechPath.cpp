#include<bits/stdc++.h>
using namespace std;
int findParent(int x,vector<int>&par)
{
    while(par[x]!=x)
    {
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
    int n,u,v,q,m;
    cin>>n>>m>>q;
    vector<int>ran(n+1),par(n+1);
    for(int i=1;i<=n;i++)
    {
        ran[i]=0;
        par[i]=i;
    }   
    while(m--)
    {
        cin>>u>>v;
        int paru=findParent(u,par);
        int parv=findParent(v,par);
        if(paru!=parv)
            unio(paru,parv,par,ran);
    }
    while(q--)
    {
        cin>>u>>v;
        int paru=findParent(u,par);
        int parv=findParent(v,par);
        if(paru==parv)
            cout<<"There exists a path between "<<u<<" and "<<v<<endl;
        else
            cout<<"There doesn't exists a path between "<<u<<" and "<<v<<endl;
    }
    return 0;
}

/*
Sample Input:
6 4 4
1 2
1 3
4 6
4 5
5 6
4 3
2 3
6 2
Sample Output:
There exists a path between 5 and 6
There doesn't exists a path between 4 and 3
There exists a path between 2 and 3
There doesn't exists a path between 6 and 2
*/