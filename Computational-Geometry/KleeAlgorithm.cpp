#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef struct points 
{
	int x, y;
}points;

vector<points>plane;

int findunion(vector<points>line) 
{
	int size=line.size();
	vector<pair<int, bool>>points(size*2);
	for(int i=0;i<size;i++)
	{
		points[i*2]=make_pair(line[i].x,false);
		points[i*2+1]=make_pair(line[i].y,true);
	}
	sort(points.begin(),points.end());
	int answer=0,counter=0;
	for(int i=0;i<size*2;i++)
	{
		if(counter)
			answer+=(points[i].x-points[i-1].x);
		if(points[i].y)
			counter--;
		else
			counter++;
	}
	return answer;
}

int main()
{
	int n;
	cin>>n;
	plane.resize(n);
	for(int i=0;i<n;i++)
		cin>>plane[i].x>>plane[i].y;
	int ans=findunion(plane);
	cout<<ans;
	return 0;

}

/*
Sample Input:
4
2 4
5 6
3 7
1 6
Sample Output:
6
*/
