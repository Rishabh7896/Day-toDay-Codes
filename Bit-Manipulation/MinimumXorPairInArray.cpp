#include<bits/stdc++.h>
using namespace std;

void minimumxor(int *A,int n)
{
    int ele1,ele2;
    int ans=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        int x=A[i]^A[i+1];
        if(x<ans)
        {
            ans=x;
            ele1=A[i];
            ele2=A[i+1];
        } 
    }
    cout<<ele1<<" ^ "<<ele2<<" : "<<ans;
}

int main() 
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    sort(A,A+n);
    minimumxor(A,n);
    return 0;
}

/*
Sample Input :
4
0 2 5 7
Sample Output:
0 ^ 2 : 2
The Minimum xor value.
*/