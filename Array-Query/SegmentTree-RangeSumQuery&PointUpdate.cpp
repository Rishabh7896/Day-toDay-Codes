#include<bits/stdc++.h>
using namespace std;

int constructsg(vector<int>&arr,int front,int back,vector<int>&sgtree,int index)
{
	if(front==back)
	{
		sgtree[index]=arr[front];
		return arr[front];
	}
	int mid=(front+back)/2;
	sgtree[index]=constructsg(arr,front,mid,sgtree,index*2+1)+constructsg(arr,mid+1,back,sgtree,index*2+2);
	return sgtree[index];
}
int sum(vector<int>&sgtree,int front,int back,int left,int right,int index)
{
	if(left<=front && right>=back)
		return sgtree[index];
	if(back<left || front>right)
		return 0;
	int mid=(front+back)/2;
	return sum(sgtree,front,mid,left,right,2*index+1)+sum(sgtree,mid+1,back,left,right,2*index+2);
}
void update(vector<int>&sgtree,int front,int back,int location,int diff,int index)
{
    if(location<front || location>back)
        return;
    sgtree[index]=sgtree[index]+diff;
    if(back!=front)
    {
        int mid=(front+back)/2;
        update(sgtree,front,mid,location,diff,2*index + 1);
        update(sgtree,mid+1,back,location,diff,2*index + 2);
    }
}
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int treesize=1<<((int)(ceil(log2(n)))+1)-1;
	vector<int>sgtree(treesize);
	constructsg(arr,0,n-1,sgtree,0);
	int q;
	cin>>q;
	while(q--)
	{
		//0 based indexing
		string type;;
		cin>>type;
		if(type=="update")
		{
			int location,value;
			cin>>location>>value;
			int diff=value-arr[location];
			arr[location]=value;
			update(sgtree,0,n-1,location,diff,0);
		}
		else
		{
			int left,right;
			cin>>left>>right;
			cout<<sum(sgtree,0,n-1,left,right,0)<<endl;
		}
	}
	return 0;
}

/*
Sample Input1:
10
10 4 2 5 7 1 0 6 8 3
6
query 1 5
update 3 6
query 1 5
query 5 9
update 7 3
query 5 9
Sample Output1:
19
20
18
15
*/