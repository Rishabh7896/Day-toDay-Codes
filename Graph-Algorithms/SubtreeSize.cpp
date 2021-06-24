#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
vector<bool>vis(100005,0);
vector<int>subsize(100005,0);

int dfs(int node)
{
    vis[node]=1;
    int currsize=1;
    for(auto child:adj[node])
        if(vis[child]==0)
            currsize+=dfs(child);
    subsize[node]=currsize;
    return currsize;
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        cout<<"Subtree size of "<<i<<" is: "<<subsize[i]<<endl;
}

/*
Sample Input:
8 7
1 7
1 2
2 4
2 3
2 5
3 8
1 6
Sample Output:
Subtree size of 1 is: 8
Subtree size of 2 is: 5
Subtree size of 3 is: 2
Subtree size of 4 is: 1
Subtree size of 5 is: 1
Subtree size of 6 is: 1
Subtree size of 7 is: 1
Subtree size of 8 is: 1
*/