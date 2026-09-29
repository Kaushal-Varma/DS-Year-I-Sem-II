#include <stdio.h>
#include <stdlib.h>

struct node {
    int data,priority;
    struct node *link;
};

struct node *temp, *p, *ptr, *front = NULL, *rear = NULL;

void enqueue() {
    int isThere = 0;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &ptr->data);

    printf("Enter Priority of data: ");
    scanf("%d", &ptr->priority);

    ptr->link=NULL;

    if (front==NULL) {
        front=ptr;
        rear=ptr;
    }
    else if (ptr->priority < front->priority) {
        ptr->link=front;
        front=ptr;
    }
    else if (ptr->priority > rear->priority) {
        rear->link=ptr;
        rear=ptr;
    }
    else {
        temp=front;

        while (ptr->priority >= temp->priority) {
            if (ptr->priority == temp->priority) {
                isThere++;
                break;
            }
            p=temp;
            temp=temp->link;
        }
        if (isThere==1) {
            printf("Element with same priority already exists...\n");
        }
        else {
            p->link=ptr;
            ptr->link=temp; 
        }
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