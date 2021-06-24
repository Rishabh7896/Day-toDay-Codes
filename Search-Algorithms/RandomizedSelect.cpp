#include<bits/stdc++.h>
using namespace std;

int random(int min, int max) 
{
    int range=max-min+1;
    int num=min+(rand()%range);
    return num;
}

int partition(int arr[],int p,int r) 
{
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
        if (arr[j]<=x)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    swap(arr[i+1],arr[r]);
    return i+1;
}

int randomizedpartition(int arr[],int p,int r) 
{
    int i=random(p,r);
    swap(arr[r],arr[i]);
    return partition(arr,p,r);
}

int randomizedselect(int arr[], int p, int r, int i)
{
    if(p>r)
        return false;
    if(p==r) 
        return arr[p];
    int q=randomizedpartition(arr,p,r);
    int k=q-p+1;
    if(i==k) 
        return arr[q];
    else if(i<k) 
        return randomizedselect(arr,p,q-1,i);
    else
        return randomizedselect(arr,q+1,r,i-k);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int key;
    cin>>key;
    cout<<(randomizedselect(arr,0,n-1,key)?"Element Found":"Element not found");
    return 0;
}

/*
Sample Input1:
10
10 4 2 5 7 1 0 6 8 3
-1
Sample Output1:
Element not found
Sample Input2:
10
10 4 2 5 7 1 0 6 8 3
3
Sample Output2:
Element found
*/