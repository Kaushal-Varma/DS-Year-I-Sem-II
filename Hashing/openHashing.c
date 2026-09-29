#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// K MOD 10 Open Hashing Program

struct node {
    int data;
    struct node* link;
};

struct node *ptr, *head, *temp;
struct node* chain[MAX]; //This array is for the hashing Table 

void insert(int key) {
    
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->link = NULL;
    key = key%MAX;

    if (chain[key] == NULL)
        chain[key] = temp;
    else {
        ptr=chain[key];
        while (ptr->link != NULL)
            ptr=ptr->link;
        ptr->link = temp;
    }
}

void display() {
    for (int i = 0; i<=MAX-1; i++) {
        if (chain[i] == NULL) 
            printf("%d-> NULL\n", i);
        else {
            temp = chain[i];
            printf("%d-> ", i);
            while (temp != NULL) {
                printf("%d ", temp->data);
                temp=temp->link;
            }
            printf("\n");   
        }
    }
}

int main(void) {
    int ch,data;

    while(1) {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                display();
                break;
            case 3: return 0;
            default: printf("Invalid Input\n");
        }
    }
}
