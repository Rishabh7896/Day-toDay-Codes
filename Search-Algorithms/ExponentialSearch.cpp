#include<bits/stdc++.h>
using namespace std;

bool binarysearch(int arr[],int left,int right,int key)
{
    if(right>=left)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==key)
            return true;
        if(arr[mid]>key)
            return binarysearch(arr,left,mid-1,key);
        return binarysearch(arr,mid+1,right,key);
    }
    return false;
}

bool exponentialsearch(int *arr, int n, int key)
{
    if(arr[0]==key)
        return true;
    int i=1;
    while(i<n && arr[i]<=key)
        i=i*2;
    int mini=i<(n-1)?i:(n-1);
    return binarysearch(arr,i/2,mini,key);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int key;
    cin>>key;
    cout<<(exponentialsearch(arr,n,key)?"Element Found":"Element not found");
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