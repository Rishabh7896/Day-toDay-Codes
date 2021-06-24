#include <bits/stdc++.h>
using namespace std;

vector<int>edges[100000];
vector<int>vis(100000,0); 

bool checkCycle(int src)
{
    queue<pair<int,int>>q;
    vis[src]=1;
    q.push(make_pair(src,-1));
    while (!q.empty())
    {
        auto pair=q.front();
        int node=pair.first;
        int prev=pair.second;
        q.pop();
        for (auto child:edges[node])
        {
            if (vis[child]==0)
            {
                vis[child]=1;
                q.push(make_pair(child,node));
            }
            else if(child!=prev)
                return true;
        }
    }
    return false;
}

int main()
{
    int n,m,u,v,res=0;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(vis[i]==0)
            if(checkCycle(i))
                res=1;
    if(res)
        cout<<"There exists a cycle in this graph";
    else
        cout<<"There does not exists a cycle in this graph";
    return 0;
}

/*
Sample Input:
11 10
1 2
2 4
3 5
5 6
5 10
6 7
7 8
10 9
9 8
8 11
Sample Output:
There exists a cycle in this graph
*/
