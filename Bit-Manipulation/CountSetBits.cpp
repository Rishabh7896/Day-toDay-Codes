#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int c=0;
	while(n) 
	{
		n&=(n-1);
		c++;
    }
    cout<< c;
}

/*
Sample Input:
5
Sample Output:
2
*/

