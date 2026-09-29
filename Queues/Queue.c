#include <stdio.h>

int q[10], front=-1, rear=-1;


void enqueue() {
    int data;
    if (rear==9) {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1) {
        printf("Enter data: ");
        scanf("%d", &data);
        front++;
        rear++;
        q[front] = data;
    }
    else {
        printf("Enter data: ");
        scanf("%d", &data);
        rear++;
        q[rear] = data;
    }
}

void dequeue() {
    if (front == -1 || front>rear) 
        printf("Stack underflow\n");
    
    else
        printf("Dequeued element = %d\n", q[front++]);
}

void display() {
    if (front==-1 && rear == -1)
        printf("Queue is empty\n");
    else {
        for (int i = front; i<=rear; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Top element = %d\n", q[front]);
    }
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