#include <bits/stdc++.h>
using namespace std;

int flippedbits(int n1,int n2) 
{
    int count=0,n=n1^n2;
    while(n) 
    {
        if (n&1)
            count++;
        n=n>>1;
    }
    return count;
}

int main()
{
    int n1,n2;
    cin>>n1>>n2;
    cout<<flippedbits(n1,n2);
    return 0;
}

/*
Sample Input:
12 24
Sample Output:
2
*/
