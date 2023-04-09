#include<stdio.h>

int front= - 1,rear= - 1;
int queue[100];
int max=100;

void push(int x)
{
    if(rear==max-1)
    {
        printf("Queue overflow.\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear=rear+1;
    queue[rear]=x;
    printf("Element %d pushed into queue.\n",x);
}

void pop()
{
    if(front== -1 || front>rear)
    {
        printf("Stack underflow.\n");
        return;
    }
    printf("Element deleted from queue is : %d\n",queue[front]);
    front= front+1;
}

void print()
{
    int i;
   if(front== -1 || front>rear)
    {
        printf("Stack underflow.\n");
        return;
    } 
    printf("Require queue is : \n");
    for(i=front;i<=rear;i++)
    {
        printf("%d->",queue[i]);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);

    pop();
    print();

    return 0;
}