#include<bits/stdc++.h>
using namespace std;

void update(int fenwick[],int ind,int val,int n)
{
	while(ind<=n)
	{
		fenwick[ind]+=val;
		ind+=(ind&(-ind));
	}
}
int query(int fenwick[],int ind)
{
    int sum=0;
    while(ind>0)
    {
        sum+=fenwick[ind];
        ind-=(ind&(-ind));
    }
    return sum;
}
int range(int fenwick[],int l,int r)
{
    return query(fenwick,r)-query(fenwick,l-1);
}
int main()
{
	int n;
	cin>>n;
	int arr[n+1]={0};
	int fenwick[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		update(fenwick,i,arr[i],n);
	}
	int q;
	cin>>q;
	while(q--)
	{
		//1 based indexing
		int l,r;
		cin>>l>>r;
		cout<<range(fenwick,l,r)<<endl;
	}
	return 0;
}

/*
Sample Input1:
10
10 4 2 5 7 1 0 6 8 3
5
1 3
2 6
4 9
5 6
1 10
Sample Output1:
16
19
27
8
46
*/