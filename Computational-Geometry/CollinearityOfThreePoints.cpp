#include <bits/stdc++.h>
using namespace std;

struct Point 
{
    int x;
    int y;
};

bool checkcollinear(Point a, Point b, Point c) 
{
    int area=0;
    area=a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if(area==0)
        return true;
    else
        return false;
}

int main() 
{
    Point a,b,c;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    if(checkcollinear(a,b,c))
        cout<<"The given points are collinear"<<endl; 
    else
        cout<<"The given points are not collinear"<<endl;
    return 0;
}

/*
Sample Input1:
1 1 2 2 3 3
Sample Output1:
The given points are collinear

Sample Input2:
1 1 2 2 3 2
Sample Output2:
The given points are not collinear
*/
