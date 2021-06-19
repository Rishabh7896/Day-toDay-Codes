#include<bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int>arr,int key,int lb,int ub) 
{
    while(lb<=ub) 
    {
        int mid=((lb+ub)/2);
        if(arr[mid]==key)
            return true;
        else if(arr[mid]>key)
            ub=mid-1;
        else
            lb=mid+1;
    }
    return false;
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
    bool result=binarysearch(arr,key,0,n);
    if(result)
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
