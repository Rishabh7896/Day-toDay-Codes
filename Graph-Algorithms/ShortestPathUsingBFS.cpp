#include<bits/stdc++.h>
using namespace std;

void bfs(int source,vector<int>adj[],bool visited[],vector<int>dist[])
{
    queue<pair<int,vector<int>>>q; 
    q.push({source,{1}});
    visited[source]=true;
    while(!q.empty())
    {
        auto curr=q.front();
        dist[curr.first]=curr.second;
        q.pop();
        for(auto node:adj[curr.first])
        {
            if(!visited[node])
            {
                curr.second.push_back(node);
                q.push({node,curr.second});
                visited[node]=true;
                curr.second.pop_back();
            }
        }
    }
}

int main()
{
    int n,m,u,v; 
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    vector<int>dist[n+1];
    bfs(1,adj,visited,dist);
    for(int i=1;i<=n;i++)
    {
        int size=dist[i].size();
        cout<<"Dist from 1 to "<<i<<" is: "<<size<<endl;
        cout<<"Path from 1 to "<<i<<" is: ";
        for(int j=0;j<size-1;j++)
            cout<<dist[i][j]<<" -> ";
        cout<<dist[i][size-1];
        cout<<endl;
    }
    return 0;
}

/*
sample Input:
8 7
1 7
1 2
2 4
2 3
2 5
3 8
1 6
Sample Output:
Dist from 1 to 1 is: 1
Path from 1 to 1 is: 1
Dist from 1 to 2 is: 2
Path from 1 to 2 is: 1 -> 2
Dist from 1 to 3 is: 3
Path from 1 to 3 is: 1 -> 2 -> 3
Dist from 1 to 4 is: 3
Path from 1 to 4 is: 1 -> 2 -> 4
Dist from 1 to 5 is: 3
Path from 1 to 5 is: 1 -> 2 -> 5
Dist from 1 to 6 is: 2
Path from 1 to 6 is: 1 -> 6
Dist from 1 to 7 is: 2
Path from 1 to 7 is: 1 -> 7
Dist from 1 to 8 is: 4
Path from 1 to 8 is: 1 -> 2 -> 3 -> 8
*/
