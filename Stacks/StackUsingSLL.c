#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *head=NULL, *tail=NULL, *ptr, *temp, *p;

void push() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    if (head==NULL) {
        head=ptr;
        tail=ptr;
    }
    else { 
        tail->link=ptr;
        tail=ptr;
    }
}

void pop() {
    if (head==NULL) {
        printf("Stack underflow\n");
    }
    else if (head->link==NULL) {
        free(head);
        head=NULL;
        tail=NULL;
    }
    else {
        temp=head;
        while (temp->link != NULL) {
            p=temp;
            temp=temp->link;
        }
        p->link=NULL;
        free(temp);
        tail=p;
}
}

void display() {
    if (head == NULL) {
        printf("No data to display\n");
    }
    else {
        temp=head;
        while (temp->link != NULL) {
            printf("%d ", temp->data);
            temp=temp->link;
        }
        printf("%d\n", tail->data);
    }
}

int main() {
    int op;
    while (1) {
        printf("\n----STACK OPERATIONS----\n 1. POP\n 2. PUSH\n 3. DISPLAY\n 4. EXIT\n Enter your choice: ");
        scanf("%d", &op);
        printf("\n");
        switch(op) {
            case 1:
                pop();
                break;
            case 2:
                push();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf(" INVALID INPUT, TRY AGAIN!\n ");
        }
    }

}