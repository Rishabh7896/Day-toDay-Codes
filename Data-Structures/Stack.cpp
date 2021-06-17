#include<bits/stdc++.h>
#define MAXSIZE 100

struct stack
{
    int num[MAXSIZE];
    int top;
};

int isfull(struct stack *node)
{
    return node->top==MAXSIZE-1;
}
int isempty(struct stack *node)
{
    return node->top==-1;
}
void push(struct stack *node,int data)
{
    if(isfull(node))
    {
        printf("Stack Full\n");
        return;
    }
    node->num[++node->top]=data;
    printf("%d pushed to stack\n",data);

}
void pop(struct stack *node)
{
    if(isempty(node))
    {
        printf("Stack Empty\n");
        return;
    }
    printf("Element pop: %d\n",node->num[node->top]);
    node->top--;
}
int main()
{
    struct stack node;
    int ch,num;
    node.top=-1;
    while(1)
    {
        printf("1. Push Data to stack\n");
        printf("2. Pop Data from stack\n");
        printf("3. Stack is Full\n");
        printf("4. Stack is Empty\n");
        printf("Enter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter data: ");
                scanf("%d",&num);
                push(&node,num);
                break;

            case 2:pop(&node);
                break;

            case 3:num=isfull(&node);
                if(num==0)
                    printf("Stack is Not Full\n");
                else
                    printf("Stack is Full\n");
                break;

            case 4:num=isempty(&node);
                if(num==0)
                    printf("Stack is Not Empty\n");
                else
                    printf("Stack is Empty\n");
                    break;

            default:exit(0);
        }
    }
    return 0;
}

