#include<bits/stdc++.h>
using namespace std;

bool interpolationSearch(int arr[],int n,int key) 
{
    int low=0,high=(n-1);
    while(low<=high && key>=arr[low] && key<=arr[high]) 
    {
        if(low==high)
        {
            if(arr[low]==key) 
                return true;
            return false;
        }
        int pos=low+(((double)(high-low)/(arr[high]-arr[low]))*(key-arr[low]));
        if(arr[pos]==key)
            return true;
        if(arr[pos]<key)
            low=pos+1;
        else
            high=pos-1;
    }
    return false;
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
    cout<<(interpolationSearch(arr,n,key)?"Element Found":"Element not found");
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