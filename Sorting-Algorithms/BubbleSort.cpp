#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int>&a,int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
            	swap(a[j],a[j+1]);
}

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	bubblesort(a,n);
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
