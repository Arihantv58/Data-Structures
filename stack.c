#include<stdio.h>
#include<stdlib.h>

int stack[8];
int maxsize= 8;
int top = -1;

void push(int x)
{
   if(top==maxsize-1)
   {
      printf("Stack overflow.\n");
      return;
   }
   top= top+1;
   stack[top]=x;
   printf("%d pushed.\n",x);
}

int pop()
{
   if(top<0)
   {
      printf("Stack is empty.\n");
      return 0;
   }
   int data = stack[top];
   top--;
   return data;
}

void print()
{
   if(top<0)
   {
      printf("Stack is empty.\n");
      return;
   }
   while(top!=-1)
   {
      int data = pop();
      printf("%d<-",data);
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
   push(8);
   push(9);

   print();

   return 0;
}