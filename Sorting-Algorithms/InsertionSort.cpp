#include<bits/stdc++.h>
using namespace std;

void insertionsort(vector<int>&a,int n)
{
    for(int i=1;i<n;i++)
    {
        int v=a[i];
        int j=i-1;
        while(j>=0 && a[j]>v)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }
}

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	insertionsort(a,n);
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
