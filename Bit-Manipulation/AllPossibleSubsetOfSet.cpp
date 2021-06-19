#include<bits/stdc++.h>
using namespace std;

void findsubset(int arr[],int len)
{
    for(int i=0;i<(1<<len);i++)
    {
        for(int j=0;j<len;j++)
        {
            if(i & (1<<j))
            {
                cout<<arr[j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    findsubset(arr,n);
    return 0;
}

/*
Sample Input:
4
1 2 3 4
Sample Output:
1
2
1 2
3
1 3
2 3
1 2 3
4
1 4
2 4
1 2 4
3 4
1 3 4
2 3 4
1 2 3 4
*/