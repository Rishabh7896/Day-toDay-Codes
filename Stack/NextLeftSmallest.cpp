#include <bits/stdc++.h>
using namespace std;

void nextgreatestright(int a[],int n,vector<int>&res)
{
    int next;
    stack<int> elements;
    elements.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        next=i;
        while(!elements.empty() && a[elements.top()]>a[next])
        {
            res[elements.top()]=a[next];
            elements.pop();
        }
        elements.push(next);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int>res(n,-1);
    nextgreatestright(a,n,res);
    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
}

/*
Sample Input:
8
9 0 5 2 4 6 7 1
OUTPUT:
-1 -1 0 0 2 4 6 0
*/
