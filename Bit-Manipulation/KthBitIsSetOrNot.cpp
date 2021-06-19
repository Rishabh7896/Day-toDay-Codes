#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	if(n&(1ll<<(k-1)))
		cout<<"Yes"<<"\n";
	else
	  cout<<"No"<<"\n";
}

/*
Sample Input1:
15
4
Sample Output1:
Yes

Sample Input1:
8
2
Sample Output1:
No
*/

