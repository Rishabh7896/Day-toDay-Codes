#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
	int length=s.size();
	stack<char> st;
	int i,mid=length/2;
	for(i=0;i<mid;i++)
		st.push(s[i]);
	if(length%2!=0)
		i++;
	char ele;
	while(s[i]!='\0')
	{
		ele=st.top();
		st.pop();
        if(ele!=s[i])
            return false;
		i++;
	}
    return true;
}

int main()
{
    string s;
    cin>>s;
    cout<<(isPalindrome(s)?"Is Palindrome":"Not Palindrome");
	return 0;
}

/*
Sample Input1:
banana
Sample Output1:
Not Palindrome

Sample Input2:
saippuakivikauppias
Sample Output2:
Is Palindrome
*/
