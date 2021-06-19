#include<bits/stdc++.h>
using namespace std;

void postfixToPrefix(string s)
{
    stack<string> str;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        {
            string operand1=str.top();
            str.pop();
            string operand2=str.top();
            str.pop();
            string prefix_part=s[i]+operand2+operand1;
            str.push(prefix_part);
        }
        else
        {
            str.push(string(1,s[i]));
        }
    }
    while(!str.empty())
    {
        cout<<str.top();
        str.pop();
    }
}

int main()
{
    string s;
    cin>>s;
    postfixToPrefix(s);
}

/*
Sample Input:
ABC/-A
Sample Output:
A-A/BC
*/
