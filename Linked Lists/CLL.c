#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node *temp, *p, *ptr, *head = NULL, *tail = NULL;

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
            head->link=head;
        }
        else {
            tail->link=ptr;
            tail=ptr;
            tail->link=head;
        }}}

void ins_begin() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;

    if (head==NULL) {
        head=ptr;
        tail=ptr;
        tail->link=ptr;
    }
    else {
        ptr->link=head;
        tail->link=ptr;
        head=ptr;
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

void ins_end() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    if (tail==NULL) {
        tail=ptr;
        head=ptr;
        tail->link=ptr;
    }
    else {
        tail->link=ptr;
        ptr->link=head;
        tail=ptr;
    }}

void del_begin() {
    if(head==NULL) {
        printf("Deletion not possible\n");
    }
    else {
        temp=head;
        head=head->link;
        free(temp);
    }}

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

void del_end() {
    if (tail==NULL) {
        printf("Deletion not possible\n");
    }
    else {
        temp=head;
        while (temp!=tail->link) {
            p=temp;
            temp=temp->link;
        }
        p->link=head;
        tail=p;
        free(temp);
    }}

void display() {
    if (head==NULL) {
        printf("No data to display\n");
    }
    else if (head->link == head) {
        printf("%d ", head->data);
    }
    else {
        temp=head;
        while (temp->link!=head) {
            printf("%d ", temp->data);
            temp=temp->link;
        }
        printf("%d\n", tail->data);

    }}

int main() {
    int ch,op;

    while(1) {
        printf("\n1.Create");
        printf("\n2.Insert");
        printf("\n3.Delete");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
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

                switch(op) {
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
                switch(op) {
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