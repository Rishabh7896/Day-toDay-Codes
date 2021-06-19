#include<bits/stdc++.h>
using namespace std;

bool poweroftwo(int n)
{
	return (n&&!(n&n-1));
}
int main()
{
	int num;
	cin>>num;
	cout<<(poweroftwo(num)?"Yes":"No")<<endl;
}

/*
Sample Input:
64
Sample Output:
Yes
*/

