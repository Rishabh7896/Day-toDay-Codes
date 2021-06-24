#include<bits/stdc++.h>
using namespace std;

typedef struct POINT
{
	int x;
	int y;
}POINT;

int orientation(POINT p,POINT q,POINT r)
{
	int slope = (p.y - r.y) * (p.x - q.x) - (p.y - q.y) * (p.x - r.x);
	if (slope > 0)
		return 1;
	if (slope < 0)
		return -1;
	else
		return 0;
}

void printPoint(POINT a)
{
	cout << a.x << " " << a.y;
}

bool isSame(POINT a, POINT b)
{
	return (a.x == b.x && a.y == b.y) ? 1 : 0;
}

void convexHull(POINT arr[], int n)
{
	if (n < 3)
		return;
	vector<POINT> result;
	int leftMost = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[leftMost].x > arr[i].x)
		{
			leftMost = i;
		}
	}
	result.push_back(arr[leftMost]);
	int curr = leftMost;
	while (1)
	{
		int nextTarget = (curr + 1) % n;
		for (int i = 0; i < n; i++)
		{
			int o = orientation(arr[curr], arr[i], arr[nextTarget]);
			if (o == -1)
			{
				nextTarget = i;
			}
		}
		if (nextTarget == leftMost)
			break;
		result.push_back(arr[nextTarget]);
		curr = nextTarget;
	}
	for (int i = 0; i < result.size(); i++)
	{
		printPoint(result[i]);
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	POINT arr[n];
	for (int i = 0; i < n; i++)
	{
		POINT p;
		cin >> p.x >> p.y;
		arr[i] = p;
	}
	convexHull(arr, n);
}

/*
Sample Input:
6
0 3
2 2
0 1
0 2
0 0
-1 0
Sample Output:
-1 0
0 3
2 2
0 0
*/

