#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int price[n];
	int span[n];
	for(int i=0;i<n;i++)
		cin >> price[i];
	stack<pair<int,int>>s;
	s.push({1,price[0]});
	span[0]=1;
	for(int i=1;i<n;i++)
	{
		int currSpan=1;
		int currPrice=price[i];
		auto p=s.top();
		int topSpan=p.first;
		int topPrice=p.second;
		while(s.size() && topPrice<=currPrice)
		{
			currSpan+=topSpan;
			s.pop();
			if (s.size())
			{
				p=s.top();
				topSpan=p.first;
				topPrice=p.second;
			}
			else
				break;
		}
		span[i]=currSpan;
		s.push({currSpan, currPrice});
	}
	for(int i=0;i<n;i++)
		cout<<span[i]<<" ";
}

/*
Sample Input:
5
30 35 40 38 35
Sample Output:
1 2 3 1 1
*/
