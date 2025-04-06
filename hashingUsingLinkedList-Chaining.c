#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Node for linked list
typedef struct Node
{
    int roll;
    char name[100];
    struct Node *next;
} Node;

Node *table[SIZE]; // array of pointers to Node

// Hash function
int hash(int roll)
{
    return roll % SIZE;
}

// Create new node
Node *createNode(int roll, char name[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Insert using chaining at head
void insert(int roll, char name[])
{
    int index = hash(roll);
    Node *newNode = createNode(roll, name);

    // Insert at head of the linked list (or you can append)
    newNode->next = table[index];
    table[index] = newNode;
}

// Insert using chaining at head
/*
    void insert(int roll, char name[]) {
    int index = hash(roll);
    struct Node* newNode = createNode(roll, name);

    if (table[index] == NULL) {
        // First node at this index
        table[index] = newNode;
    } else {
        // Traverse to the end and append
        struct Node* current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
*/

// Display hash table
void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d ->", i);
        Node *current = table[i];
        while (current != NULL)
        {
            printf("[Roll: %d, Name: %s] → ", current->roll, current->name);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main(void)
{
    // Initialize table with NULL
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = NULL;
    }

    insert(101, "Arun");
    insert(111, "Vijay");
    insert(121, "Meena");

    display();
    return 0;
}