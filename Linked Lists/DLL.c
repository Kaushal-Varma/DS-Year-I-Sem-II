#include <stdio.h>
#include <stdlib.h>

//  This is Doubly Linked list
struct node {
    int data;
    struct node *link1, *link2;
};

struct node *head=NULL,*tail=NULL,*ptr,*temp,*p;

void create() {
    int data,n,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++) {
        printf("Enter the data: ");
        scanf("%d",&data);
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->link1=NULL;
        ptr->link2=NULL;
        if(head==NULL) {
            head=ptr;
            tail=ptr;
        }
        else {
            tail->link2=ptr;
            ptr->link1=tail;
            tail=ptr;
        }}}

void ins_begin() {
    int data;
    printf("Enter data to insert: ");
    scanf("%d",&data);

    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link1=NULL;
    ptr->link2=NULL;

    if(head==NULL) {
        head=ptr;
        tail=ptr;
    }
    else {
        ptr->link2=head;
        head->link1=ptr;
        head=ptr;
    }}

void ins_end() {
    int data;

    printf("Enter data to insert: ");
    scanf("%d",&data);

    ptr=(struct node *)malloc(sizeof(struct node));

    ptr->data=data;
    ptr->link1=NULL;
    ptr->link2=NULL;

    if(head==NULL) {
        head=ptr;
        tail=ptr;
    }
    else {
        tail->link2=ptr;
        ptr->link1=tail;
        tail=ptr;
    }}

void ins_middle() {
    int pos,i,data;

    printf("Enter data: ");
    scanf("%d",&data);

    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link1=NULL;
    ptr->link2=NULL;
    printf("Enter position: ");
    scanf("%d",&pos);

    temp=head;
    i=1;
    while(i<pos) {
        p=temp;
        temp=temp->link2;
        i++;
    }
    p->link2=ptr;
    ptr->link1=p;
    ptr->link2=temp;
    temp->link1=ptr;
}

void del_begin() {
    if(head==NULL) {
        printf("Deletion not possible\n");
    }
    else {
        p=head;
        head=head->link2;

        if(head!=NULL)
            head->link1=NULL;
        else
            tail=NULL;

        free(p);
        p=NULL;
    }}

void del_end() {
    if(tail==NULL) {
        printf("Deletion not possible\n");
    }
    else {
        p=tail;
        tail=tail->link1;
        if(tail!=NULL) {
            tail->link2=NULL; }
        else{
            head=NULL; }

        free(p);
        p=NULL;
    }}

void del_middle() {
    int pos,i;
    if(head==NULL) {
        printf("Deletion not possible\n");
        return;
    }
    printf("Enter position: ");
    scanf("%d",&pos);

    temp=head;
    i=1;

    while(i<pos) {
        temp=temp->link2;
        i++;
    }
    p=temp->link1;
    p->link2=temp->link2;
    if(temp->link2!=NULL) {
        temp->link2->link1=p; }

    if(temp==tail) {
        tail=p; }

    free(temp);
}

void display() {
    if(head==NULL) {
        printf("No data\n");
    }
    else {
        temp=head;
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp=temp->link2;
        }

        printf("\n");
    }}

int main() {
    int ch,op;
    while(1) {
        printf("\n1. Create\n2. Insert\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                create();
                break;
            case 2:

                printf("\n1.Beginning");
                printf("\n2.Middle");
                printf("\n3.End");
                printf("\nEnter choice: ");
                scanf("%d",&op);
                switch(op){
                    case 1:
                        ins_begin();
                        break;

                    case 2:
                        ins_middle();
                        break;

                    case 3:
                        ins_end();
                        break;

                    default:
                        printf("Invalid Choice\n");
                }
                break;
            case 3:
                printf("\n1.Beginning");
                printf("\n2.Middle");
                printf("\n3.End");
                printf("\nEnter choice: ");
                scanf("%d",&op);
                switch(op){
                    case 1:
                        del_begin();
                        break;
                    case 2:
                        del_middle();
                        break;
                    case 3:
                        del_end();
                        break;
                    default:
                        printf("Invalid Choice\n");
                }
                break;
            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }}
    return 0;
}