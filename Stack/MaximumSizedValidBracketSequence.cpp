#include <bits/stdc++.h>
using namespace std;

int lengthseq(string s,int len)
{
    int curlen=0,maxlen=0;
    stack<char>st;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            if(!st.empty())
            {
                if(st.top()=='(')
                {
                    st.pop();
                    curlen+=2;
                    maxlen=max(maxlen,curlen);
                }
                else
                {
                    while(!st.empty())
                        st.pop();
                }
            }
            else
                curlen=0;
        }
    }
    return maxlen;
}

int main()
{
    string s;
    cin>>s;
    cout<<lengthseq(s,s.length())<<endl;
}

/*
Sample Input:
((()())
Sample Output:
6
*/
