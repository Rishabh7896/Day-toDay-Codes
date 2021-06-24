#include<bits/stdc++.h>
using namespace std;

int longestpalindrome(string s1)
{
	int n1=s1.length(),n2=s1.length();
	string s2=s1;
	int dp[n1+1][n2+1];
	for(int i=0;i<=n1;i++)
		for(int j=0;j<=n2;j++)
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(s1[i-1]==s2[n2-j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	return dp[n1][n2];
}

int main()
{
	string s;
	cin>>s;
	cout<<longestpalindrome(s);
	return 0;
}

/*
Sample Input:
SHASYP
GFSHAD
Sample Output:
SHA
*/
