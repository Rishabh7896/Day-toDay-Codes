#include <bits/stdc++.h>

#define e 1e-10
#define x first
#define y second

using namespace std;

typedef struct point
{
    double x, y;
}point;

vector<point> plane;
stack<point> hull;

double area(point a, point b, point c)
{
    return (a.x - b.x) * (b.y - c.y) - (a.y - b.y) * (b.x - c.x);
}

double dis(point a, point b)
{
    return sqrt((a.x = b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(point a, point b)
{
    if (area(plane[0], a, b) < -e)
    {
        return 0;
    }
    if (area(plane[0], a, b) > e)
    {
        return 1;
    }
    return dis(a, plane[0]) < dis(b, plane[0]);
}

int main()
{
    int n;
    point tmp;
    cin>>n;
    plane.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>plane[i].x>>plane[i].y;
        if(i)
        {
            if(plane[i].x<plane[0].x)
                swap(plane[i],plane[0]);
        }
    }
    sort(plane.begin()+1,plane.end(),cmp);
    hull.push(plane[0]);
    hull.push(plane[1]);
    for(int i=2;i<n;i++)
    {
        tmp=hull.top();
        hull.pop();
        while (hull.size() && area(plane[i], tmp, hull.top())>-e)
        {
            tmp = hull.top();
            hull.pop();
        }
        hull.push(tmp);
        hull.push(plane[i]);
    }
    cout<<"The following vertices form the convex hull:\n";
    while (!hull.empty())
    {
        cout << hull.top().x << " , " << hull.top().y << endl;
        hull.pop();
    }
}

/*
Sample Input:
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
Sample Output:
4,4
3,1
0,0
0,3
*/

