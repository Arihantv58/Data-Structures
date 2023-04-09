#include<stdio.h> 
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * front;
struct node * rear;

void insert(struct node * ptr, int item) {

    ptr = (struct node * ) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    } else {
        ptr -> data = item;
        if (front == NULL) {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
        } else {
            rear -> next = ptr;
            rear = ptr;
            rear -> next = NULL;
        }
    }
}

int main() {
    struct node * head = NULL;
    insert(head, 10);
    insert(head, 20);

    printf("front element: %d", front -> data);
    return 0;
}