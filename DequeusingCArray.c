#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX], front=-1, rear=-1;

void b_insert() {
    int data;

    if ((rear + 1) % MAX == front) {
        printf("Deque is full\n");
    }
    else {
        printf("Enter data: ");
        scanf("%d", &data);

    if (front == -1) {
        front=0;
        rear=0;
    }
    else {
        rear=(rear+1)%MAX;
    }

    deque[rear]=data;
    }
}

void f_delete() {
    if (front == -1) 
        printf("Deque is empty\n");
    else {
        int pos=front;

        if (front == rear) {
            front=-1;
            rear=-1;
        }
        else
            front=(front+1)%MAX;

        printf("Element deleted = %d\n", deque[pos]);
    }
}

void f_insert() {
    int data;

    if ((rear + 1) % MAX == front) 
        printf("Deque is full\n");
    else {
        printf("Enter data: ");
        scanf("%d", &data);

        if (front == -1) {
            front=0;
            rear=0;
        }
        else
            front=(front-1+MAX)%MAX;

        deque[front]=data;
    }
}

void b_delete() {
    if (front == -1) 
        printf("Deque is empty\n");
    else {
        int pos=rear;

        if (front == rear) {
            front=-1;
            rear=-1;
        }
        else 
            rear=(rear-1+MAX)%MAX;

        printf("Element deleted = %d\n", deque[pos]);
    }
}

void f_display() {
    int i;

    if (front == -1) 
        printf("Deque is empty\n");
    else {
        i=front;

        while (1) {
            printf("%d ", deque[i]);

            if (i == rear)
                break;

            i=(i+1)%MAX;
        }

        printf("\n");
    }
}

void b_display() {
    int i;

    if (front == -1) 
        printf("Deque is empty\n");
    else {
        i=rear;

        while (1) {
            printf("%d ", deque[i]);

            if (i == front)
                break;

            i=(i-1+MAX)%MAX;
        }

        printf("\n");
    }
}

int main(void) {
    int ch, op;

    while(1) {
        printf("\n1. Front Operations\n2. Back Operations\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\n1. Insert\n2. Delete\n3. Display\n");
                printf("Enter choice: ");
                scanf("%d", &op);
                switch(op) {
                    case 1: f_insert(); break;
                    case 2: f_delete(); break;
                    case 3: f_display(); break;
                    default: printf("Invalid Input\n");
                }
                break;
                
            case 2:
                printf("\n1. Insert\n2. Delete\n3. Display\n");
                printf("Enter choice: ");
                scanf("%d", &op);
                switch(op) {
                    case 1: b_insert(); break;
                    case 2: b_delete(); break;
                    case 3: b_display(); break;
                    default: printf("Invalid Input\n");
                }
                break;
            case 3: return 0;
            default: printf("Invalid Input\n");
        }
    }
}