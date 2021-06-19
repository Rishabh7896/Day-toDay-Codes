#include <bits/stdc++.h> 
using namespace std; 

int left_rotate_bits(int n, int cnt,int total)
{
    int msb;
    for(cnt=cnt%total;cnt>0;cnt--)
    {
        msb=(n>>(total-1))&1;
        n=((n<<1)&(~(1<<(total))));
        n=n|msb;
    }
    return n;
}

int right_rotate_bits(int n,int cnt,int total)
{
    int lsb;
    for(cnt=cnt%total;cnt>0;cnt--)
    {
        lsb=n&1;
        n=(n>>1)|(lsb<<(total-1));
    }
    return n;
}

int main()
{
    string type;
    int n,bit;
    cin>>n>>type>>bit;
    int temp=n,totalbit=0;
    while(temp)
    {
        totalbit++;
        temp>>=1;
    }
    if(type=="left")
        cout<<left_rotate_bits(n,bit,totalbit);  
    else
        cout<<right_rotate_bits(n,bit,totalbit);
    return 0;
}


/*
Sample Input1:
39 
left 14
Sample Output1:
30

Sample Input2:
39 
right 14
Sample Output2:
57
*/