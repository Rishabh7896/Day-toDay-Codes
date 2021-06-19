#include<bits/stdc++.h>
using namespace std;
struct trie 
{
    trie *zero,*one;
};

void insert(int num,trie *root) 
{
    trie *ptr=root;
    for(int i=31;i>=0;i--) 
    {
        int h = (num>>i & 1);
        if(h==0) 
        {
            if(ptr->zero==NULL)
                ptr->zero=new trie();
            ptr=ptr->zero;
        }
        else 
        {
            if(ptr->one==NULL)
                ptr->one=new trie();
            ptr=ptr->one;
        }
    }
}

int comp(int num,trie *root) 
{
    trie *ptr = root;
    int sum=0;
    for(int i=31;i>=0;i--) 
    {
        sum=sum<<1;
        int h=(num>>i&1);
        if(h==0) 
        {
            if(ptr->one) 
            {
                sum++;
                ptr=ptr->one;
            }
            else 
                ptr=ptr->zero;
        }
        else 
        {
            if(ptr->zero) 
            {
                sum++;
                ptr=ptr->zero;
            }
            else 
                ptr=ptr->one;
        }
    }
    return sum;
}

int findMaximumXOR(vector<int>&ar) 
{
    trie *root = new trie(); 
    for(int i=0;i<ar.size();i++)
        insert(ar[i],root);
    int maxm=0;
    for(int i=0;i<ar.size();i++)
        maxm=max(comp(ar[i],root),maxm);
    return maxm;
}

int main() 
{
    int n;
    cin>>n;
    vector<int>ar(n);
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<findMaximumXOR(ar);
    return 0;
}

/* 
Sample Input:
6
3 10 5 25 2 8
Sample Output:
28

The Maximum XOR of two numbers in the array.
*/
