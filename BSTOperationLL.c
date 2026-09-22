#include <stdio.h>
#include <stdlib.h>


/*
  STILL
   IN
DEVELOPMENT
*/


struct node {
    int data;
    struct node *l1, *l2;
};

struct node *root=NULL, *ptr, *p, *temp;

void insert(struct node *temp, struct node *ptr) {
    if (temp==NULL)
        root = ptr;
    else {
        if (temp->data > ptr->data) {
            if (temp->l1 == NULL)
                temp->l1 = ptr;
            else
                insert(temp->l1, ptr);
        }
        else {
            if (temp->l2==NULL)
                temp->l2=ptr;
            else
                insert(temp->l2, ptr);
        }
    }
}

void inorder(struct node *root) {
    if (root == NULL)
        return 0;
    else {
        inorder(root->l1);
        printf("%d", root->data);
        inorder(root->l2);
    }
}

void preorder(struct node *root) {
    if (root == NULL)
        return 0;
    else {
        printf("%d", root->data);
        preorder(root->l1);
        preorder(root->l2);
    }
}

void postorder(struct node *root) {
    if (root == NULL)
        return 0;
    else {
        postorder(root->l1);
        postorder(root->l2);
        printf("%d", root->data);
    }
}

int search(struct node *root, int data) { 
    if (root == NULL) {
        printf("%d not found\n", data); 
        return 0;
    }
    if (root->data == data) { 
        printf("%d is found successfully\n", root->data); 
        return 1; 
    } 
    else if (root->data > data) 
        return search(root->l1, data); 
    else
        return search(root->l2, data); 
}





int main(void) {
    int ch;

    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. InOrder\n5. PreOrder\n6. PostOrder\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                ptr = (struct node *)malloc(sizeof(struct node));
                printf("Enter data: ");
                scanf("%d", &ptr->data);
                ptr->l1=NULL;
                ptr->l2=NULL;
                insert(root, ptr);

                break;
            case 2:
                return 0;
                break;
            
            case 3:
                
        }
    }
}