#include<bits/stdc++.h>
using namespace std;

int shellsort(int arr[],int n)
{
    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i+=1)
        {
            int temp=arr[i];
            int j;           
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    }
    return 0;
}

int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    shellsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

/*
Sample Input:
5
2 4 1 5 4
Sample Output:
1 2 4 4 5 
*/
