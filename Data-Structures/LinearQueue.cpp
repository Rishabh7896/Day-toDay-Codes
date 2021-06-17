#include<bits/stdc++.h>
using namespace std;

#define MAX 100

typedef struct Queue
{
	int rear;
	int front;
	int elements[MAX];
}queuee;

int empty(queuee *pq);
int full(queuee *pq);
void enqueue(queuee *pq,int x);
int dequeue(queuee *pq);
void display(queuee *pq);

int main()
{
	queuee q;
	q.front=-1;
	q.rear=-1;
	int choice,num;
	while(1)
	{
		printf("\n1)Insert Queue\n2)Delete Queue\n3)Display\n4)Exit\n");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter a value:");
			        scanf("%d",&num);
			        if(full(&q))
			             printf("\nQueue is full !!!!");
			        else
			            enqueue(&q,num);
			        break;
			case 2: if(!empty(&q))
			        {
			        num=dequeue(&q);
			        printf("\nDeleted Data=%d",num);
			        }
			        else
			            printf("\nQueue is empty !!!!");
			        break;
			case 3: display(&q);
			        break;
			default:exit(1);
		}
	}
}
int empty(queuee *pq)
{
	if(pq->rear==-1)
	    return(1);
	return(0);
}
int full(queuee *pq)
{
	if((pq->rear+1)%MAX==pq->front)
		return(1);
    return(0);
}
void enqueue(queuee *pq,int x)
{
	if(pq->rear==-1)
	    pq->rear=pq->front=0;
	else
	    pq->rear=(pq->rear+1)%MAX;
	pq->elements[pq->rear]=x;
}
int dequeue(queuee *pq)
{
    int x;
    x=pq->elements[pq->front];
    if(pq->rear==pq->front)
    {

        pq->rear=-1;
        pq->front=-1;
    }
    else
        pq->front=(pq->front+1)%MAX;
	return(x);
}
void display(queuee *pq)
{
	int i;
	if(empty(pq))
	{
		printf("Queue Empty\n");
		return;
	}
	for(i=pq->front;i!=pq->rear;i=(i+1)%MAX)
		printf("%d\t",pq->elements[i]);
	printf("%d\t",pq->elements[i]);
}
