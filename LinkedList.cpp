#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void push_head(Node** head,int data)
{
    Node* newNode = new Node();
    newNode->data= data;
    newNode->next= *head;
    *head= newNode;
    cout<<newNode->data<<" has pushed."<<endl;
}

void push_end(Node** head,int data)
{
    Node* newNode = new Node();
    newNode->data= data;
    newNode->next= NULL;

    Node* last = *head;

    if(last==NULL)
    {
        last = newNode;
        cout<<newNode->data<<" has pushed."<<endl;
    }

    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next= newNode;
    cout<<newNode->data<<" has pushed."<<endl;
}

void push_at(Node*head,int data,int index)
{
    int count=1;
    while(count!=index-1)
    {
        head = head->next;
        count++;
    }
    Node* newNode = new Node();
    newNode->data=data;
    newNode->next=head->next;
    head->next=newNode;
    cout<<newNode->data<<" has pushed."<<endl;
}

void del_node(Node** head,int key)
{
    Node* temp = (*head);
    Node* prev = NULL;
    if(temp != NULL && temp->data==key)
    {
        cout<<temp->data<<" has deleted."<<endl;
        (*head)=temp->next;
        delete temp;
        return ;
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
    cout<<temp->data<<" has deleted."<<endl;
    prev->next=temp->next;
    delete temp;
}


void printList(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

void printRand(Node* head, int x)
{
    int count=1;
    while(count!=x)
    {
        head=head->next;
        count++;
    }
    cout<<"The required data is : "<<x;
}

int main()
{
    Node* head = new Node();
    Node* end = new Node();

    head->data= 7;
    head->next= end;

    end->data= 8;

    push_head(&head,6);
    push_head(&head,2);
    push_head(&head,1);

    push_end(&head,9);
    push_end(&head,10);
    push_end(&head,11);

    push_at(head,3,3);
    push_at(head,4,4);
    push_at(head,5,5);
    printList(head);

    del_node(&head,1);


    printList(head);

    printRand(head,5);

    return 0;
}