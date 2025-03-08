#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
    struct Node *back;
};

// Function to create a new node
struct Node *createNode(int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->back = NULL;
    return newNode;
}

// Function to convert an array to a linked list
struct Node *ConvertArrayToDoublyLinkedList(int arr[], int size)
{

    if (size == 0)
    {
        return NULL;
    }

    struct Node *head = createNode(arr[0]);
    struct Node *previous = head;

    for (int i = 1; i < size; i++)
    {
        struct Node *temp = createNode(arr[i]);
        temp->back = previous;
        previous->next = temp;
        previous = temp;
    }
    return head;
}

struct Node *deleteHeadOfDoublyLinkedList(struct Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    struct Node *prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    free(prev);
    return head;
}

// Function to print the linked list
void printLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
    printf("\n");

    int arr[] = {2, 5, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node *head = ConvertArrayToDoublyLinkedList(arr, size);
    head = deleteHeadOfDoublyLinkedList(head);

    printf("Linked List: ");
    printLinkedList(head);

    freeLinkedList(head);

    printf("\n");
    return 0;
}
