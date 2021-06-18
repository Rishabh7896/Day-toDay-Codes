#include<bits/stdc++.h>
using namespace std;

string binary(int n)
{
	string s="";
	while(n)
	{
		s+=to_string(n&1);
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}

int main()
{
	int n;
	cin>>n;
    cout<<binary(n)<<endl;
}

/*
Sample Input1:
12345
Sample Output1:
11000000111001

Sample Input2:
987654
Sample Output2:
11110001001000000110
*/

