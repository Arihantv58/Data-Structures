#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};
typedef struct Node Node;
void push_head(Node**head, int data)
{
    Node*newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=*head;
    *head=newNode;
    printf("%d has pushed.\n",newNode->data);
}

void push_end(Node**end, int data)
{
    Node*newNode = malloc(sizeof(Node));
    newNode->data=data;
    Node* last = (*end);
    
    if(last==NULL)
    {
        last=newNode;
        (*end)=newNode;
        printf("%d has pushed.\n",newNode->data);
    }
    
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newNode;
    newNode->next=NULL;
    (*end)=newNode;
    printf("%d has pushed.\n",newNode->data);
}

void push_at(Node* head, int data, int index)
{
    int count=1;
    while(count!=index-1)
    {
        head=head->next;
        count++;
    }
    Node*newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->next= head->next;
    head->next=newNode;
    printf("%d has pushed.\n",newNode->data);
}

void del_node(Node** head, int key)
{
    Node* temp = (*head);
    Node* prev = NULL;
    
    if(temp!=NULL && temp->data==key)
    {
        printf("%d has deleted.\n",temp->data);
        (*head)=temp->next;
        free(temp);
        return;
    }
    if(temp==NULL)
    {
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    printf("%d has deleted.\n",temp->data);
    prev->next=temp->next;
    free(temp);
}

void printlist(Node** head)
{
    Node* temp = (*head);
    printf("Required List is :\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void print_rand(Node* head,int index)
{
    int count=1;
    while(count!=index)
    {
        head=head->next;
        count++;
    }
    printf("Require data is : %d\n",head->data);
}

int main()
{
    Node*head = malloc(sizeof(Node));
    Node*end = malloc(sizeof(Node));
    
    head->data=1;
    head->next=end;
    
    end->data=2;
    end->next=NULL;
    
    push_head(&head,3);
    push_end(&end,4);
    push_head(&head,5);
    push_at(head,6,3);
    printlist(&head);
    del_node(&head,5);
    
    printlist(&head);
    
    print_rand(head,3);
    printf("%d",end->data);

    return 0;
}