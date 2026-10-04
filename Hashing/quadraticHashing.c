#include <stdio.h>

#define MAX 100
#define EMPTY -1

int hashTable[MAX];
int size;

void insert()
{
    int key, index, i, pos;

    printf("Enter key: ");
    scanf("%d", &key);

    index = key % size;

    for(i = 0; i < size; i++)
    {
        pos = (index + i * i) % size;

        if(hashTable[pos] == EMPTY)
        {
            hashTable[pos] = key;

            printf("Key %d inserted at index %d\n", key, pos);
            return;
        }
    }

    printf("Hash table is full\n");
}

void search()
{
    int key, index, i, pos;

    printf("Enter key to search: ");
    scanf("%d", &key);

    index = key % size;

    for(i = 0; i < size; i++)
    {
        pos = (index + i * i) % size;

        if(hashTable[pos] == EMPTY)
        {
            printf("Key %d not found\n", key);
            return;
        }

        if(hashTable[pos] == key)
        {
            printf("Key %d found at index %d\n", key, pos);
            return;
        }
    }

    printf("Key %d not found\n", key);
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for(i = 0; i < size; i++)
    {
        if(hashTable[i] == EMPTY)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int ch, i;

    printf("Enter hash table size: ");
    scanf("%d", &size);

    if(size <= 0 || size > MAX)
    {
        printf("Invalid size\n");
        return 0;
    }

    for(i = 0; i < size; i++)
        hashTable[i] = EMPTY;

    while(1)
    {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Input\n");
        }
    }
}
