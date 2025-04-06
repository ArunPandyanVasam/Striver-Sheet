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

Node *table[SIZE]; // Hash table with chaining (array of linked lists)

// Function prototypes
int hash(int roll);
Node *createNode(int roll, char name[]);
void insertHead(int roll, char name[]);
void insertTail(int roll, char name[]);
Node *search(int roll); // Function prototype for search
void update(int roll, char newName[]);
void delete(int roll);
void display();

// Hash function: simple modulo
int hash(int roll)
{
    return roll % SIZE;
}

// Create a new node
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

// Insert at head (chaining)
void insertHead(int roll, char name[])
{
    int index = hash(roll);
    Node *newNode = createNode(roll, name);

    // Insert at the head of the linked list
    newNode->next = table[index];
    table[index] = newNode;

    printf("Inserted at head: Roll %d, Name %s at index %d\n", roll, name, index);
}

// Insert at tail (chaining)
void insertTail(int roll, char name[])
{
    int index = hash(roll);
    Node *newNode = createNode(roll, name);

    // If no elements at this index, simply insert the new node
    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        // Traverse to the end of the list and append the new node
        Node *current = table[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Inserted at tail: Roll %d, Name %s at index %d\n", roll, name, index);
}

// Search by roll number
Node *search(int roll)
{
    int index = hash(roll);
    Node *current = table[index];

    while (current != NULL)
    {
        if (current->roll == roll)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Update name by roll number
void update(int roll, char newName[])
{
    Node *target = search(roll);
    if (target)
    {
        strcpy(target->name, newName);
        printf("Updated Roll %d to Name %s\n", roll, newName);
    }
    else
    {
        printf("Roll %d not found. Cannot update.\n", roll);
    }
}

// Delete by roll number
void delete(int roll)
{
    int index = hash(roll);
    Node *current = table[index];
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->roll == roll)
        {
            if (prev == NULL)
                table[index] = current->next;
            else
                prev->next = current->next;

            free(current);
            printf("Deleted Roll %d from index %d\n", roll, index);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Roll %d not found for deletion.\n", roll);
}

// Display full hash table
void display()
{
    printf("\n--- Hash Table ---\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d → ", i);
        Node *current = table[i];
        while (current != NULL)
        {
            printf("[Roll: %d, Name: %s] → ", current->roll, current->name);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Driver code
int main(void)
{
    // Initialize table
    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    // Insert test data using head insertion
    insertHead(101, "Arun");
    insertHead(111, "Vijay");
    insertHead(121, "Meena");

    // Insert test data using tail insertion
    insertTail(102, "Amit");
    insertTail(112, "Priya");
    insertTail(122, "Ravi");

    display();

    // Duplicate insert check
    insertHead(101, "NewName");

    // Search
    Node *found = search(111);
    if (found)
        printf("Found → Roll: %d, Name: %s\n", found->roll, found->name);
    else
        printf("Roll not found.\n");

    // Update
    update(111, "Vijay Kumar");
    update(200, "Ghost");

    // Delete
    delete(121);
    delete(200);

    display();

    return 0;
}
