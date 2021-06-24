#include <bits/stdc++.h> 
using namespace std; 

int ternarysearch(int l,int r,int key,int ar[])   
{ 
    while(r>=l) 
	{
        int mid1=l+(r-l)/3; 
        int mid2=r-(r-l)/3;
        if(ar[mid1]==key || ar[mid2]==key) 
            return true;
        if(key<ar[mid1])
            r=mid1-1;
        else if(key>ar[mid2])
            l=mid2+1; 
        else 
		{
            l=mid1+1; 
            r=mid2-1; 
        } 
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
    cout<<(ternarysearch(0,n,key,arr)?"Element Found":"Element not found");
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