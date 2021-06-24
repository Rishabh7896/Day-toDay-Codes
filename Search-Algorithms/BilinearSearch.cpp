#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

bool bilinearsearch(vector<int>&a,int n,int key)
{
    int front=0,back=n-1;
    while(front<=back)
    {
        if(a[front]==key) 
            return true;
        if(a[back]==key)
            return true;
        front++;
        back--;
    }
    return false;
}

int main()
{
    int n; 
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int key; 
    cin>>key;
    cout<<(bilinearsearch(a,n,key)?"Element Found":"Element not found");
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