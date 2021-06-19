#include<bits/stdc++.h>
using namespace std;

void bucketsort(float arr[], int n)
{
    vector<float>b[n];
    for(int i=0;i<n;i++)
    {
        int bi=n*arr[i];
        b[bi].push_back(arr[i]);
    }
    for(int i=0;i<n;i++)
        sort(b[i].begin(),b[i].end());
    int index=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<b[i].size();j++)
            arr[index++]=b[i][j];
}

int main() 
{
    int n;
    cin>>n;
    float arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bucketsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

/*
Sample Input:
4
0.123 0.008 0.7 0.4
Sample Output:
0.008 0.123 0.4 0.7
*/
