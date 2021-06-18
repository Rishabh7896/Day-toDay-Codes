#include<bits/stdc++.h>
using namespace std;

int basicgcd(int a,int b) 
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int extendedgcd(int a,int b,int *x,int *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int gcd=extendedgcd(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}


int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int x,y;
    cout<<basicgcd(n1,n2)<<" "<<extendedgcd(n1,n2,&x,&y);
}

/*
Sample Input1:
17 35
Sample Output1:
1 1

Sample Input2:
50 100
Sample Output2:
50 50
*/

