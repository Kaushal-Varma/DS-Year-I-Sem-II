#include <stdio.h>
#include <stdlib.h>

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

struct node* delete(struct node* root, int data) {

    if (root==NULL) {
        printf("%d not found\n", data);
        return root;
    }
    
    if (data < root->data)
        root->l1 = delete(root->l1, data);
    else if (data > root->data)
        root->l2 = delete(root->l2, data);
    else {
        if (root->l1 == NULL && root->l2 == NULL) {
            free(root);
            root = NULL; // No dangling ptr
        }
        else if (root->l1 == NULL) {
            temp = root;
            root=root->l2;
            free(temp);
        }
        else if (root->l2 == NULL) {
            temp = root;
            root=root->l1;
            free(temp);
        }
        else {
            temp=root->l2;

            while (temp->l1 != NULL)
                temp=temp->l1;
            
                root->data = temp->data;
                root->l2 = delete(root->l2, temp->data);
        }
    }
    return root;
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
    int ch, data;

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
                printf("Enter data(delete): ");
                scanf("%d", &data);

                root = delete(root, data);
                break;
            
            case 3:
                printf("Enter data(search): ");
                scanf("%d", &data);

                search(root, data);
                break;
            
            case 4:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    inorder(root);
                    printf("\n");
                }
                break;
            
            case 5:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    preorder(root);
                    printf("\n");
                }
                break;
            
            case 6:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    postorder(root);
                    printf("\n");
                }
                break;

            case 7: return 0;
            default: printf("Invalid Input\n");


                
        }
    }
}