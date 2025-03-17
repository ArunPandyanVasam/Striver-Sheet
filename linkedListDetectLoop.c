#include <stdio.h>
#include <stdlib.h>

// Node structure represents a node in a linked list
struct Node
{
    int data;          // Data stored in the node
    struct Node *next; // Pointer to the next node in the list
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the linked list
void freeLinkedList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
    // Create a linked list with values 1, 3, 2, and 4
    struct Node *head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);

    // Print the original linked list
    printf("Original Linked List: ");
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedListRecursive(head);

    // Print the reversed linked list
    printf("Reversed Linked List: ");
    printLinkedList(head);

    // Free allocated memory
    freeLinkedList(head);

    return 0;
}
