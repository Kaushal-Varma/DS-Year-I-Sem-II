#include <stdio.h>
#include <stdlib.h>

// Implementation of Stack C Program...

struct node {
    int a[10];
    int top; 
};

struct node stack; // VARIABLE

void create() {
    int n;
    printf(" Enter number of data elements to enter[1-10]: ");
    scanf("%d", &n);
    
    if (n>10) {
        printf(" Try Again! \n");
        exit(1);
    }    
    else {
        stack.top=n-1;
        for (int i=0;i<=stack.top; i++) {
            printf(" Enter data to push: ");
            scanf("%d", &stack.a[i]);
        }
    }
} 

void push() {
    int data;
    if (stack.top==9) {
        printf(" Stack Overflow\n");
    }

    else {
        printf(" Enter data: ");
        scanf("%d", &data);
        stack.top++;
        stack.a[stack.top] = data;
    }
}

void pop() {
    if (stack.top == -1) {
        printf(" Stack Underflow\n ");
    }
    else {
        printf(" The pop item = %d\n", stack.a[stack.top]);
        stack.top--;
    }
}

void display() {
    if (stack.top == -1) {
        printf(" No data to display!\n ");
    }
    else {
        for (int i = 0; i<=stack.top; i++) {
            printf("%d ", stack.a[i]);
        }
    }
}

int main() {
    int op;
    while (1) {
        printf("\n----STACK OPERATIONS----\n 1. CREATE\n 2. POP\n 3. PUSH\n 4. DISPLAY\n 5. EXIT\n Enter your choice: ");
        scanf("%d", &op);
        printf(" \n");
        switch(op) {
            case 1:
                create();
                break;
            case 2:
                pop();
                break;
            case 3:
                push();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf(" INVALID INPUT, TRY AGAIN!\n ");
        }
    }

}
