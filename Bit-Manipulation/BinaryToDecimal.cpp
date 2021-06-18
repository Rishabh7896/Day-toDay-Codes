#include<bits/stdc++.h>
using namespace std;

int decimal(string s)
{
	int n=s.length();
	int exp=1;
	int res=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='1')
			res+=exp;
		exp*=2;
	}
	return res;
}

int main()
{
	string s;
	cin>>s;
	cout<<decimal(s);
}

/*
Sample Input1:
11000000111001
Sample Output1:
12345

Sample Input2:
11110001001000000110
Sample Output2:
987654
*/

