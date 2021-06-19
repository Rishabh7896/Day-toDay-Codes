#include<bits/stdc++.h>
using namespace std;

string removeSpaces(string &s)
{
	int n = s.length();
	string trimmed;
	for(int i = 0; i < n; i++)
		if(s[i]!=' ')
			trimmed.push_back(s[i]);
	return trimmed;
}

int precedence(char c)
{
	if(c=='*' || c=='/')
		return 3;
	else if(c=='+' || c=='-')
		return 2;
	else
		return 1;
}

int calculate(int num1,int num2,char symbol)
{
	if(symbol=='*')
		return num1*num2;
	else if(symbol=='/')
		return num1/num2;
	else if(symbol=='+')
		return num1+num2;
	else if(symbol=='-')
		return num1-num2;
	return -1;
}

int evaluate(string token){
	stack<int>values;
	stack<char>operators;
	int i;
	int n=token.length();
	for(i=0;i<n;i++)
	{
		if(isdigit(token[i]))
		{
			int value=0;
			while(i<n && isdigit(token[i]))
			{
				value=value*10+(token[i]-'0');
				i++;
			}
			values.push(value);
			i--;
		}
		else if(token[i]=='(')
			operators.push('(');
		else if(token[i]==')')
		{
			while(!operators.empty() && operators.top()!='('){
				int val2 = values.top();
				values.pop();
				int val1=values.top();
				values.pop();
				char symbol=operators.top();
				operators.pop();
				int calculated_value=calculate(val1, val2, symbol);
				values.push(calculated_value);
			}
			operators.pop();
		}
		else
		{
			if(operators.empty())
				operators.push(token[i]);
			else
			{
				if(precedence(token[i])>precedence(operators.top()))
					operators.push(token[i]);
				else
				{
					while(!operators.empty() && (precedence(token[i]) <= precedence(operators.top())))
					{
						int val2=values.top();
						values.pop();
						int val1=values.top();
						values.pop();
						char symbol=operators.top();
						operators.pop();
						int calculated_value = calculate(val1,val2,symbol);
						values.push(calculated_value);
					}
					operators.push(token[i]);
				}
			}
		}
	}
	while(!operators.empty())
	{
		int val2=values.top();
		values.pop();
		int val1=values.top();
		values.pop();
		char symbol=operators.top();
		operators.pop();
		int calculated_value=calculate(val1,val2,symbol);
		values.push(calculated_value);
	}
	return values.top();
}

int main()
{
	string s;
	getline(cin,s);
	string trimmed = removeSpaces(s);
	cout<<evaluate(trimmed)<<endl;
	return 0;
}

/*
Sample Input1:
((2+4)*2)/(2+4)
Sample Output1:
2

Sample Input2:
((7*3)+3)/(1+2) 
Sample Output2:
8
*/
