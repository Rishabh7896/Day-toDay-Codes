#include<bits/stdc++.h>
using namespace std;

void countsort(int n,vector<int>&a)
{
	int max=*max_element(a.begin(),a.end());
	int min=*min_element(a.begin(),a.end());
	int range=max-min+1;

	vector<int>count(range),output(n);
	for(int i=0;i<n;i++)
		count[a[i]-min]++;

	for(int i=1;i<count.size();i++)
		count[i]+=count[i-1];
	for(int i=n-1;i>=0;i--) 
	{
		output[count[a[i]-min]-1]=a[i];
		count[a[i]-min]--;
	}
	for(int i=0;i<n;i++)
		a[i]=output[i];
}

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	countsort(n,a);
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
