#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initHash()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

void insert()
{
    int key, index, i, probeIndex;

    printf("Enter key to insert: ");
    scanf("%d", &key);

    index = key % TABLE_SIZE;
    i = 0;

    while(i < TABLE_SIZE)
    {
        probeIndex = (index + i * i) % TABLE_SIZE;

        if(hashTable[probeIndex] == -1)
        {
            hashTable[probeIndex] = key;

            printf("Inserted %d at index %d\n", key, probeIndex);
            return;
        }

        i++;
    }

    printf("Cannot insert %d using quadratic probing (table full or quadratic cycle)\n", key);
}

void display()
{
    printf("\n--- Quadratic Probing Hash Table ---\n");

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i] == -1)
        {
            printf("Index %d: EMPTY\n", i);
        }
        else
        {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main()
{
    int choice;

    initHash();

    do
    {
        printf("\n=== QUADRATIC PROBING MENU ===\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    while(choice != 3);

    return 0;
}