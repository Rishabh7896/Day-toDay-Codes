#include<bits/stdc++.h>
using namespace std;

int jumpsearch(vector<int>arr,int n,int find)
{
    int step=sqrt(n);
    int pre_step=0;
    while(arr[min(step,n)-1]<find) 
    { 
        pre_step=step; 
        step+=sqrt(n); 
        if(pre_step>=n)
            return -1;
    }
    while(arr[pre_step]<find)
    {
        pre_step++;
        if(pre_step==min(step,n))
            return -1;
    }
    if(arr[pre_step]==find)
        return pre_step;
    else
        return -1;
}

int main() 
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
    sort(arr.begin(),arr.end());
    int key;
    cin>>key;
    int result=jumpsearch(arr,n,key);
    if(result!=-1)
        cout<<"Element found"<<endl;
    else
        cout<<"Element not found"<<endl;
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