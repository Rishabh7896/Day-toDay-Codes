#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&a,int l,int m,int r)
{
    int i,j,k,n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[m+1+j];
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>&a,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
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
