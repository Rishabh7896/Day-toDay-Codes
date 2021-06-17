#include<std/s++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
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


	    break;
            default:exit(0);
        }
    }

}
node getnode()
{
   node t;
   t=(node)malloc(sizeof(struct Node));
   if(t==NULL)
   {
       printf("Not created\n");
       exit(0);
   }
   t->next=NULL;
       return t;
}
node insert_front(int num,node head)
{
     node t;
    t=getnode();
    t->data=num;
    t->next=NULL;
    if(head==NULL)
    {
        return t;
    }
    t->next=head;
    return t;
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
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");
}
node delete_front(node head)
{
    node t;
    t=head;
    head=t->next;
    printf("The deleted node data :%d\n",t->data);
    free(t);
    return head;
}
 int count(node head)
 {
     node c;
     int counter=0;
     c=head;
     while(c!=NULL)
     {
         counter++;
         c=c->next;

     }
     return counter;
 }
int search(node head,int key)
{
    node c;
    c=head;
    while(c!=NULL)
    {
        if(c->data==key)
        {
            return 1;
        }
        c=c->next;
    }
    return 0;
}
int frequency(node head,int key)
{
  int count=0;
  node c;
  c=head;
  while(c!=NULL)
  {
    if(c->data==key)
    {
      count++;

    }
    c=c->next;
  }
  return count;
}
void insert_pos(node head,int num,int pos)
{
  node c,prev,t;
  prev=NULL;
  c=head;
  int count=1;
  t=getnode();
  t->data=num;
  t->next=NULL;
  while(c!=NULL&&pos!=count)
  {
    prev=c;
    c=c->next;
    count++;
  }
  prev->next=t;
  t->next=c;
}
void delete_pos(node head,int pos)
{
  node c,prev;
  int count=1;
  c=head;
  prev=NULL;
  while(c!=NULL&&pos!=count)
  {
    prev=c;
    c=c->next;
    count++;
  }
  prev->next=c->next;
  free(c);
}
node insert_rear(int num,node head)
{
  node t,c;
  c=head;
  t=getnode();
  t->data=num;
	if(head==NULL)
	{
		return t;
	}
  while(c->next!=NULL)
  {
    c=c->next;
  }
  c->next=t;
  return head;
}

node delete_rear(node head)
{
  node prev,c;
  if(head==NULL)
  {
    printf("List is empty\n");
    head==NULL;
  }
  prev=NULL;
  c=head;
  while(c->next!=NULL)
  {
    prev=c;
    c=c->next;
  }
	if(c==head)
	{
		head=NULL;
	}
	else
	{
    free(c);
  	prev->next=NULL;
	}
	return head;
}