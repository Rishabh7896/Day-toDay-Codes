#include <bits/stdc++.h>
using namespace std;

vector<int>edges[100000];
vector<bool>vis(100000,false); 

pair<int,int> bfs(int src)
{
    queue<pair<int,int>>q;
    vis[src]=true;
    q.push(make_pair(src,1));
    pair<int,int>node;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        for (auto child:edges[node.first])
            if(!vis[child])
            {
                vis[child]=true;
                q.push(make_pair(child,node.second+1));
            }
    }
    return node;
}

int main()
{
    int n,m,u,v,res=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    pair<int,int>src=bfs(1);
    fill(vis.begin(),vis.begin()+n+1,false);
    src=bfs(src.first);
    cout<<src.second;
}

/*
Sample Input:
8
1 2
1 7
2 4
4 6
2 3
3 8
2 5
Sample Output:
8
*/
