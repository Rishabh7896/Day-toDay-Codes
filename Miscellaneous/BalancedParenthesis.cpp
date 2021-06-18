#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    stack<char>st;
    for(int i=0;s[i]!='\0';i++)
        if(s[i]=='(')
           st.push('(');
        else if(!st.empty())
            st.pop();
        else
        {
            cout<<"Invalid";
            return 0;
        }
    if(st.empty())
        cout<<"Valid";
    else
        cout<<"Invalid";
    return 0;
}

/*
Sample Input1:
()()()()
Sample Output1:
Valid

Sample Input2:
()()()(
Sample Output2:
Invalid
*/

