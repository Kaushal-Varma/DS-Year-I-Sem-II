#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *head = NULL, *tail = NULL, *ptr, *temp, *p;

void create() {
    int data, n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i=1;i<=n;i++)
    {
        ptr=(struct node *)malloc(sizeof(struct node));

        printf("Enter the data: ");
        scanf("%d",&data);

        ptr->data=data;
        ptr->link=NULL;

        if(head==NULL) {
            head=ptr;
            tail=ptr;
        }
        else {
            tail->link=ptr;
            tail=ptr;
        }}}

void ins_begin() {
    int data;

    ptr=(struct node *)malloc(sizeof(struct node));

    printf("Enter data to insert: ");
    scanf("%d",&data);

    ptr->data=data;
    ptr->link=NULL;

    if(head==NULL) {
        head=ptr;
        tail=ptr;
    }
    else {
        ptr->link=head;
        head=ptr;
    }}

void ins_end() {
    int data;

    ptr=(struct node *)malloc(sizeof(struct node));

    printf("Enter data to insert: ");
    scanf("%d",&data);

    ptr->data=data;
    ptr->link=NULL;

    if(head==NULL) {
        head=ptr;
        tail=ptr;
    }
    else {
        tail->link=ptr;
        tail=ptr;
    }}

void ins_middle() {
    int pos,i,data;

    printf("Enter position to insert: ");
    scanf("%d",&pos);

    ptr=(struct node *)malloc(sizeof(struct node));

    printf("Enter data to insert: ");
    scanf("%d",&data);

    ptr->data=data;
    ptr->link=NULL;

    temp=head;

    for(i=1;i<pos;i++) {
        p=temp;
        temp=temp->link;
    }

    p->link=ptr;
    ptr->link=temp;
}

void del_begin() {
    if(head==NULL) {
        printf("Deletion not possible\n");
    }
    else {
        p=head;
        head=head->link;

        free(p);
    }}

void del_end() {
    if(head==NULL) {
        printf("Deletion not possible\n");
        return;
    }

    if(head==tail) {
        free(head);
        head=NULL;
        tail=NULL;
        return;
    }

    temp=head;

    while(temp->link!=NULL) {
        p=temp;
        temp=temp->link;
    }

    free(temp);
    tail=p;
    p->link=NULL;
}

void del_middle() {
    int pos,i;

    if(head==NULL) {
        printf("Deletion not possible\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d",&pos);

    temp=head;

    for(i=1;i<pos;i++) {
        p=temp;
        temp=temp->link;

    }

    p->link=temp->link;
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
            temp=temp->link;
        }

        printf("\n");
    }}

int main() {
    int ch,ch1;

    while(1) {
        printf("\n1.Create");
        printf("\n2.Insert");
        printf("\n3.Delete");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: create(); break;
                
            case 2:

                printf("\n1.Beginning");
                printf("\n2.Middle");
                printf("\n3.End");
                printf("\nEnter choice: ");
                scanf("%d",&ch1);

                switch(ch1) {
                    case 1: ins_begin(); break;
                    case 2: ins_middle(); break;
                    case 3: ins_end(); break;
                    default: printf("Invalid Choice\n");
                }
                break;

            case 3:

                printf("\n1.Beginning");
                printf("\n2.Middle");
                printf("\n3.End");
                printf("\nEnter choice: ");
                scanf("%d",&ch1);

                switch(ch1) {
                    case 1: del_begin(); break;
                    case 2: del_middle(); break;
                    case 3: del_end(); break;
                    default: printf("Invalid Choice\n");
                }
                break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid Choice\n");
        }}

    return 0;
}