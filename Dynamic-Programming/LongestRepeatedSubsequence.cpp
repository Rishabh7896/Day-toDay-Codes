#include<bits/stdc++.h>
using namespace std;

int longestrepeating(string s1,int m,int n,unordered_map<string,int>&lookup)
{
	if(m==0 || n==0)
		return 0;
	string key=to_string(m)+"|"+to_string(n);
	if(lookup.find(key)==lookup.end())
	{
		if(s1[m-1]==s1[n-1] && m!=n)
			lookup[key]=longestrepeating(s1,m-1,n-1,lookup)+1;
		else
			lookup[key]=max(longestrepeating(s1,m,n-1,lookup),longestrepeating(s1,m-1,n,lookup));
	}
	return lookup[key];
}

int main()
{
	string s;
	cin>>s;
	unordered_map<string,int>lookup;
	cout<<longestrepeating(s,s.length(),s.length(),lookup);
	return 0;
}

/*
Sample Input:
ATACTCGGA
Sample Output:
4
*/
