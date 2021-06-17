#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node *node;
node getnode();
node insert_front(int num,node head);
node delete_front(node head);
int count(node head);
int search(node head,int key);
int frequency(node head,int key);
void display(node head);
node insert_rear(int num,node head);
void insert_pos(node head,int num,int pos);
void delete_pos(node head,int pos);
node delete_rear(node head);
int main()
{
    node head=NULL;
    int num,ch,m,n,key,p,a,data;
    while(1)
    {
        printf("1-Insert front\n2-Insert rear\n3-Insert at a position\n4-Delete front\n5-Delete rear\n6-Delete at a position\n7-Display\n8-Count node\n9-Search\n10-Frequency\nEnter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number\n");
                   scanf("%d",&num);
                   head=insert_front(num,head);
                   break;
            case 2:printf("Enter the number\n");
                   scanf("%d",&num);
                   head=insert_rear(num,head);
                   break;
            case 3:printf("Enter the position where the node is to be inserted:\n");
                   scanf("%d",&p);
                   printf("Enter the data for node created:\n");
                   scanf("%d",&num);
                   insert_pos(head,num,p);
                   break;
            case 4:head=delete_front(head);
                   break;
            case 5:head=delete_rear(head);
                   break;
            case 6:printf("Enter the position for the node to be deleted:\n");
                   scanf("%d",&p);
                   delete_pos(head,p);
                   break;
            case 7:printf("The list contents are:\n");
                   display(head);
                   break;
            case 8:m=count(head);
                   printf("\nTotal nodes:%d\n",m);
                   break;
            case 9:printf("\nEnter the key to be found:\n");
                   scanf("%d",&key);
                   n=search(head,key);
                   if(n==1)
                   {
                       printf("\nElement found\n");
                   }
                   if(n==0)
                   {
                       printf("\nElement not found\n");
                   }
                   break;
            case 10:printf("Enter the key element to be found:\n");
                    scanf("%d",&key);
                    n=frequency(head,key);
                    printf("\nThe frequency of key element is:%d\n",n);
                    break;
            default:exit(0);
        }
    }
}
node getnode()
{
    node p;
    p=(node)malloc(sizeof(struct Node));
    if(p==NULL)
    {
        perror("Memory Error\n");
        exit(0);
    }
    p->next=p;
    p->prev=p;
    return p;
}
node insert_front(int num,node head)
{
    node p;
    p=getnode();
    p->data=num;
    if(head==NULL)
    {
        return p;
    }
    p->next=head;
    p->prev=head->prev;
    head->prev->next=p;
    head->prev=p;
    return p;
}
node insert_rear(int num,node head)
{
    node p,q;
    p=getnode();
    p->data=num;
    if(head==NULL)
    {
        return p;
    }
    q=head;
    while(q->next!=head)
    {
        q=q->next;
    }
    p->next=head;
    p->prev=q;
    q->next->prev=p;
    q->next=p;
    return head;
}
void insert_pos(node head,int num,int pos)
{
    node c,p;
    int count=1;
    p=getnode();
    c=head;
    p->data=num;
    while(c!=NULL && pos!=count)
    {
        c=c->next;
        count++;
    }
    (c->prev)->next=p;
    p->prev=c->prev;
    p->next=c;
    c->prev=p;
}
int count(node head)
{
    int count=0;
    node p=head;
    while(p->next!=head)
    {
        p=p->next;
        count++;
    }
    if(p->next==head)
        count++;
    return count;
}
int search(node head,int key)
{
    node p;
    if(head==NULL)
    {
        printf("List Empty\n");
        exit(0);
    }
    p=head;
    while(p->next!=head)
    {
        if(p->data==key)
        {
            return 1;
        }
        p=p->next;
    }
    if(p->data==key)
    {
        return 1;
    }
    return 0;
}
int frequency(node head,int key)
{
    int count=0;
    node c;
    c=head;
    while(c->next!=head)
    {
        if(c->data==key)
        {
            count++;
        }
        c=c->next;
    }
        if(c->data==key)
        {
            count++;
        }
    return count;
}
void display(node head)
{
    node t;
    if(head==NULL)
    {
        printf("Empty list\n");
        exit(0);
    }
    printf("Elements are:\n");
    t=head;
    while(t->next!=head)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("%d\t\n",t->data);
}
node delete_front(node head)
{
    node p;
    if(head==NULL)
    {
        return NULL;
    }
    p=head;
    head->next->prev=p->prev;
    head->prev->next=head->next;
    head=head->next;
    free(p);
    return head;
}
void delete_pos(node head,int pos)
{
    node c,pre;
    int count=1;
    c=head;
    pre=NULL;
    while(c!=NULL&&pos!=count)
    {
        pre=c;
        c=c->next;
        count++;
    }
    pre->next=c->next;
    c->next->prev=pre;
    free(c);
}
node delete_rear(node head)
{
    node p;
    if(head==NULL)
    {
        return NULL;
    }
    p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
    return head;
}
