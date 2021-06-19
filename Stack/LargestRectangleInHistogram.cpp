#include<bits/stdc++.h>
using namespace std;

void largestArea(int height[],int n)
{
	stack<int> s;
	int ans=0;
	int l=0,r=0;
	for(int i=0;i<n;i++)
	{
		if(s.empty())
		{
			s.push(i);
			continue;
		}
		if(height[i]>height[s.top()])
			s.push(i);
		else
		{
			while(!s.empty() && height[i]<height[s.top()])
			{
				int toBeRemoved=s.top();
				s.pop();
				int area;
				if(s.empty())
					area=height[toBeRemoved]*i;
				else
					area=height[toBeRemoved]*(i-s.top()-1);
				if (area>ans)
				{
					ans=area;
					l=(!s.empty())?s.top():0;
					r=i;
				}
				ans=max(ans,area);
			}
			s.push(i);
		}
	}
	cout<<ans<<"\n"<<l<<" "<<r;
}

int main()
{
	int n;
	cin>>n;
	int height[n];
	for(int i=0;i<n;i++)
		cin >> height[i];
	largestArea(height, n);
}

/*
Sample Input:
7
6 2 5 4 5 1 6
Sample Output:
12
1 5
*/
