#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	unordered_map<char,Node*>children;
	bool terminal;
	Node(char d){
		data=d;
		terminal=false;
	}
};

class Trie
{
	Node*root;
	public:
	Trie()
	{
		root=new Node('\0');
	}
	void insert(string w)
	{
		Node*temp=root;
		for(int i=0;w[i]!='\0';i++)
		{
			char ch=w[i];
			if(temp->children.count(ch))
				temp=temp->children[ch];
			else
			{
				Node*n=new Node(ch);
				temp->children[ch]=n;
				temp=n;
			}
		}
		temp->terminal=true;
	}
	bool find(string w)
	{
		Node*temp=root;
		for(int i=0;w[i]!='\0';i++)
		{	
			char ch=w[i];
			if(temp->children.count(ch)==0)
				return false;
			else
				temp=temp->children[ch];
		}
		return temp->terminal;
	}
	void deletion(string w)
	{
		Node*temp=root;
		for(int i=0;w[i]!='\0';i++)
		{
			char ch=w[i];
			if(temp->children.count(ch)==0)
				return;
			else
				temp=temp->children[ch];
		}
		temp->terminal=false;
	}
};

int main()
{
	Trie T;
	int n;
	cin>>n;
	string*arr=new string[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		T.insert(arr[i]);
	}
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		if(T.find(s))
			cout<<"String found"<<endl;
		else
			cout<<"String not found"<<endl;
	}
	string str;
	cin>>str;
	T.deletion(str);
	if(T.find(str))
		cout<<"String found"<<endl;
	else
		cout<<"String not found"<<endl;
}

/*Sample Input:
5
a
hello
HEllo
apple
news
7
a
hello
HEllo
not
new
news
newss

Sample Output:
String found
String found
String not found
String not found
String found
String not found
*/

