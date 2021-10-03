#include <bits/stdc++.h>
using namespace std;
 
class Node {
public:
    int data;
    Node* next;
};

void print(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}
 
// Driver code
int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
 

    head = new Node();
    second = new Node();
    third = new Node();
 
    head->data = 2;
    head->next = second; 
 
    second->data = 4;
    second->next = third;
 
    third->data = 6;
    third->next = NULL;
 
    print(head);
 
    return 0;
}