#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};
typedef struct Node Node;
void push_head(Node**head, int data)
{
    Node*newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=(*head);
    newNode->prev=NULL;
    (*head)->prev=newNode;
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
    newNode->prev=(*end);
    (*end)=newNode;
    printf("%d has pushed.\n",newNode->data);
}

void push_at(Node* head, int data, int index)
{
    Node* temp=NULL;
    int count=1;
    while(count!=index)
    {
        temp=head;
        head=head->next;
        count++;
    }
    Node*newNode = malloc(sizeof(Node));
    newNode->data=data;
    newNode->next= head;
    newNode->prev=temp;
    head->prev=newNode;
    temp->next=newNode;

    printf("%d has pushed.\n",newNode->data);
}

void del_node(Node** head, int key)
{
    Node* temp = (*head);
    Node* back = NULL;
    
    if(temp!=NULL && temp->data==key)
    {
        printf("%d has deleted.\n",temp->data);
        (*head)=temp->next;
        temp->next->prev=NULL;
        free(temp);
        return;
    }
    if(temp==NULL)
    {
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        back=temp;
        temp=temp->next;
    }
    printf("%d has deleted.\n",temp->data);
    back->next=temp->next;
    temp->next->prev=temp->prev;
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

void print_revlist(Node** end)
{
    Node* temp = (*end);
    printf("Required List is :\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->prev;
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
    head->prev=NULL;
    
    end->data=2;
    end->next=NULL;
    end->prev=head;
    
    push_head(&head,3);
    push_end(&end,4);
    push_head(&head,5);
    push_at(head,6,3);
    
    printlist(&head);
    
    printf("Head : %d\n",head->data);
    printf("End : %d\n",end->data);

    print_revlist(&end);

    del_node(&head,3);
    printlist(&head);
    print_revlist(&end);
    return 0;
}