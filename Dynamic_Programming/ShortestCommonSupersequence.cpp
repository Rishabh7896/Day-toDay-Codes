#include<bits/stdc++.h>
using namespace std;

int shortestsuperseq(string s1,string s2)
{
    int m=s1.length(),n=s2.length();
    int lookup[m+1][n+1];
    for(int i=0;i<=m;i++)
        lookup[i][0]=i;
    for(int j=0;j<=n;j++)
        lookup[0][j]=j;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(s1[i-1]==s2[j-1])
                lookup[i][j]=lookup[i-1][j-1]+1;
            else
                lookup[i][j]=min(lookup[i-1][j]+1,lookup[i][j-1]+1);
    return lookup[m][n];
}


int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<shortestsuperseq(s1,s2);
	return 0;
}

/*
Sample Input:
ABCBDAB
BDCABA
Sample Output:
9
*/
