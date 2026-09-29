#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *temp, *p, *ptr, *front = NULL, *rear = NULL;

void enqueue() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    if (rear==NULL) {
        rear=ptr;
        front=ptr;
        rear->link=ptr;
    }
    else {
        rear->link=ptr;
        ptr->link=front;
        rear=ptr;
    }}

void dequeue() {
    if(front==NULL) {
        printf("Queue is empty\n");
    }
    else {
        temp=front;
        front=front->link;
        free(temp);
    }}

void display() {
    if (front==NULL) {
        printf("No data to display\n");
    }
    else if (front->link == front) {
        printf("%d ", front->data);
    }
    else {
        temp=front;
        while (temp->link!=front) {
            printf("%d ", temp->data);
            temp=temp->link;
        }
        printf("%d\n", rear->data);

    }}

void peek() {
    if (front==NULL) 
        printf("Queue is empty\n");
    else
        printf("Top element = %d\n", rear->data);
}

int main(void) {
    int ch;
    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: return 0;
            default: printf("Invalid Input\n");
        }
    }
}
