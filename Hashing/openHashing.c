#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// K MOD 10 Open Hashing Program

struct node {
    int data;
    struct node* link;
};

struct node *head, *temp;
struct node* chain[MAX]; //This array is for the hashing Table 

void insert(int key) {
    for (i = 0; i<MAX; i++)
        chain[i] = NULL; // Initialising all chains to NULL
    
    temp = (struct node *)malloc(sizeof(struct node));
    
}