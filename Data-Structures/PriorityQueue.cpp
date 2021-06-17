#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

typedef struct data
{
	int ele;
	int pr;
}DATA;

typedef struct PRQ
{
	DATA d[SIZE];
	int front;
	int rear;
}PriorityQ;

void PQinsert(PriorityQ *PQ,int elem, int pre);
void PQdelete(PriorityQ *PQ);
int Qfull(PriorityQ *PQ);
int Qempty(PriorityQ *PQ);
void display(PriorityQ *PQ);

void PQinsert(PriorityQ *PQ,int elem, int pre)
{
	int i;
	if(Qfull(PQ))
		printf(" Overflow!!!!nn");
	else
	{
		i=PQ->rear;
		++PQ->rear;
		while(PQ->d[i].pr>=pre && i>=0)
		{
			PQ->d[i+1]=PQ->d[i];
			i--;
		}
		PQ->d[i+1].ele=elem;
		PQ->d[i+1].pr=pre;
	}
}

void PQdelete(PriorityQ *PQ)
{
	struct data p;
	if(Qempty(PQ))
		printf("Underflow\n");
	else
	{
		p=PQ->d[PQ->front];
		PQ->front=PQ->front+1;
		printf("Deleted element is %d\n",p.ele);
	}
}

int Qfull(PriorityQ *PQ)
{
	if(PQ->rear==SIZE-1)
		return 1;
	return 0;
}

int Qempty(PriorityQ *PQ)
{
	if(PQ->front > PQ->rear)
		return 1;
	return 0;
}

void display(PriorityQ *PQ)
{
	int i;
	if(Qempty(PQ)) printf("Empty Queue\n");
	else
	{
		printf("Front->");
		for(i=PQ->front;i<=PQ->rear;i++)
			printf("[%d,%d] ",PQ->d[i].ele,PQ->d[i].pr);
		printf("<-Rear");
	}
}

int main()
{
	int opn;
	int ele,pr;
	PriorityQ PQ;
	PQ.front=0;
	PQ.rear=-1;
	while(1)
	{
		printf("\nPriority Queue Operations\n");
		printf("\n1) Insert\n2) Delete\n3) Display\n4) Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&opn);
		switch(opn)
		{
			case 1:printf("\nRead the element and its Priority\n");
				scanf("%d%d",&ele,&pr);
				PQinsert(&PQ,ele,pr);
				break;

			case 2:PQdelete(&PQ);
				break;

			case 3:printf("\nStatus of Queuen\n");
				display(&PQ);
				break;

			default:  exit(0);
		}
	}
	return 0;
}
