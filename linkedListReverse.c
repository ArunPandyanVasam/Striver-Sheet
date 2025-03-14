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

// Function to reverse the linked list using a dynamic stack - BRUTE FORCE APPROACH
struct Node *reverseLinkedList(struct Node *head)
{
    if (!head)
        return NULL;

    // Count nodes to determine stack size
    int count = 0;
    struct Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    // Allocate stack dynamically
    int *stack = (int *)malloc(count * sizeof(int));
    if (!stack)
    {
        printf("Memory allocation failed for stack\n");
        return head;
    }

    // Push values onto the stack
    temp = head;
    for (int i = 0; i < count; i++)
    {
        stack[i] = temp->data;
        temp = temp->next;
    }

    // Pop values and update the linked list
    temp = head;
    for (int i = count - 1; i >= 0; i--)
    {
        temp->data = stack[i];
        temp = temp->next;
    }

    // Free allocated memory
    free(stack);
    return head;
}

/*
    // ALTERNATIVE APPROACH USING ARRAY INSTEAD OF MALLOC BUT IS IS CONSIDERED TO BE SAFEST
    struct Node* reverseLinkedList(struct Node* head) {
    struct Node* temp = head;
    int stack[1000];  // Assuming max 1000 elements for simplicity
    int top = -1;

    // Step 1: Push values onto the stack
    while (temp != NULL) {
        stack[++top] = temp->data;
        temp = temp->next;
    }

    // Step 2: Pop values and update the linked list
    temp = head;
    while (temp != NULL) {
        temp->data = stack[top--];
        temp = temp->next;
    }

    return head;
}
*/





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
    head = reverseLinkedListIterative(head);

    // Print the reversed linked list
    printf("Reversed Linked List: ");
    printLinkedList(head);

    // Free allocated memory
    freeLinkedList(head);

    return 0;
}
