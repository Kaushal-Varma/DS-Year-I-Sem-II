#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *front=NULL, *rear=NULL, *ptr, *temp;

void create() {
    int n,data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i<=n; i++) {
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);

        ptr->data=data;
        ptr->link=NULL;

        if (front == NULL) {
            front=ptr;
            rear=ptr;
        }
        else {
            rear->link=ptr;
            rear=ptr;
        }
    }
}

void enqueue() {
    int data;

    ptr=(struct node *)malloc(sizeof(struct node));

    printf("Enter data to insert: ");
    scanf("%d",&data);

    ptr->data=data;
    ptr->link=NULL;

    if(front==NULL) {
        front=ptr;
        rear=ptr;
    }
    else {
        rear->link=ptr;
        rear=ptr;
    }
}

void dequeue() {
    if(front==NULL) {
        printf("Queue underflow\n");
    }
    else {
        temp=front;
        front=front->link;

        free(temp);
    }
}

void display() {
    if(front==NULL) {
        printf("Queue is empty\n");
    }
    else {
        temp=front;

        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp=temp->link;
        }

        printf("\n");
    }
}

void peek() {
    if (front==NULL) 
        printf("Queue is empty\n");
    else
        printf("Top element = %d\n", front->data);
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