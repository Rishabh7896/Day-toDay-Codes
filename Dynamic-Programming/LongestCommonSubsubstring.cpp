#include<bits/stdc++.h>
using namespace std;

string longestsubstring(string s1,string s2)
{
	int n1=s1.length(),n2=s2.length();
	int maxlen=0,endindex=n2;
	vector<vector<int>>lookup(n1+1,vector<int>(n2+0));
	for(int i=0;i<=n1;i++)
		for(int j=0;j<=n2;j++)
			if(i==0 || j==0)
				lookup[i][j]=0;
			else if(s1[i-1]==s2[j-1])
			{
				lookup[i][j]=lookup[i-1][j-1]+1;
				if(lookup[i][j]>maxlen)
				{
					maxlen=lookup[i][j];
					endindex=i;
				}
			}
	return s1.substr(endindex-maxlen,maxlen);
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<longestsubstring(s1,s2);
	return 0;
}

/*
Sample Input:
SHASYP
GFSHAD
Sample Output:
SHA
*/
