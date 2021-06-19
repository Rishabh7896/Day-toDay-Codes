#include<bits/stdc++.h>
using namespace std;

void heapsort(vector<int>&a,int n)
{
    for(int i=n/2;i>=1;i--)
    {
        int k=i;
        int v=a[k];
        int heap=0;
        while(!heap && 2*k<=n)
        {
            int j=2*k;
            if(j<n && a[j]<a[j+1])
                j++;
            if(v>=a[j])
                heap=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }
}

int main()
{
    int n; 
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    heapsort(a,n);
    for(int i=1;i<a.size();i++)
    {
        swap(a[1],a[n]);
        n--;
        heapsort(a,n);
    }
    cout<<"Sorted Array: ";
    for(int i=1;i<a.size();i++)
        cout<<a[i]<<" ";
    return 0;
}

/*
Sample Input:
10
10 4 2 5 7 1 0 6 8 3

Sample Output:
Sorted Array: 0 1 2 3 4 5 6 7 8 10 
*/
