#include<bits/stdc++.h>
using namespace std;

int binaryexponentiation(int a,int b)
{
    int res=1;
    while(b>0)
    {
        if(b%2)
        {
            res=res*a;
        }
        a=a*a;
        b/=2;
    }
    return res;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<binaryexponentiation(a,b)<<endl;
}

/*
Sample Input1:
2 10
Sample Output1:
3672

Sample Input2:
17 6
Sample Output2:
24137569
*/

