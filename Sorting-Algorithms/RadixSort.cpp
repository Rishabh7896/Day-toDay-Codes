#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[],int n,int exp)
{
    int output[n];
    int i,count[10]={0};
    for(i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--) 
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        arr[i]=output[i];
}

void radixsort(int arr[],int n)
{
    int m=*max_element(arr,arr+n);
    for(int exp=1;m/exp>0;exp*=10)
        countsort(arr,n,exp);
}

int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    radixsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

/*
Sample Input:
5
5 3 2 4 1
Sample Output:
1 2 3 4 5
*/
