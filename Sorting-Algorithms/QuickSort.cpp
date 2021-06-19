#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&a,int left,int right)
{
    int temp,pivot=a[left];
    int i=left,j=right+1;
    do
    {
        do
        {
            i++;
        }while(a[i]<pivot && i<=right);
        do
        {
            j--;
        }while(a[j]>pivot);
        swap(a[i],a[j]);
    }while(i<j);
    swap(a[i],a[j]);

    a[left]=a[j];
    a[j]=pivot;

    return(j);
}

void quicksort(vector<int>&a,int left,int right)
{
    if(left<right)
    {
        int s=partition(a,left,right);
        quicksort(a,left,s-1);
        quicksort(a,s+1,right);
    }
}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	quicksort(a,0,n-1);
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++)
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
