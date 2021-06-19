#include<bits/stdc++.h>
using namespace std;

bool isbalanced(string expr)
{
    stack<char> s;
    char x;
    for(int i=0;i<expr.length();i++)
    {
        if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
        {
            s.push(expr[i]);
            continue;
        }
        if(s.empty())
            return false;
        x=s.top();
        s.pop();
        switch(expr[i])
        {
            case ')': if(x=='{' || x=='[') return false;
                break;

            case '}': if(x=='(' || x=='[') return false;
                break;

            case ']': if(x=='(' || x=='{') return false;
                break;
        }
    }
    return (s.empty());
}

int main()
{
    string expr;
    cin>>expr;
    if(isbalanced(expr))
        cout<<"Balanced Parenthesis";
    else
        cout<<"Unbalanced Parenthesis";
    return 0;
}

/*
Sample Input1:
((){})[]{()}
Sample Output1:
Balanced Parenthesis
Sample Input2:
{()()]}
Sample Output2:
Unbalanced Parenthesis
*/