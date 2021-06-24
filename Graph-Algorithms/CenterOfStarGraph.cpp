#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,u,v;
    cin>>n;
    vector<int>edges[n+1];    
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int center=-1;
    for(int i=1;i<=n;i++)
        if(edges[i].size()==n-1)
            center=i;
    cout<<center;
    return 0;
}

/* 
Sample Input:
4
1 2
2 3
4 2
Sample Output:
2
*/
