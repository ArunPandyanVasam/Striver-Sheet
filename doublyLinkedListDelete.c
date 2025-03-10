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

// delete head
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

// delete tail
struct Node *deleteTailOfDoublyLinkedList(struct Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    struct Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    struct Node *newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;

    free(tail);

    return head;
}

struct Node *deleteKthElement(struct Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    int ctr = 0;
    struct Node *kNode = head;
    while (kNode != NULL)
    {
        ctr++;
        if (ctr == k)
            break;
        kNode = kNode->next;
    }

    if (kNode == NULL)
    {
        printf("Invalid Position: %d\n", k);
        return head;
    }

    struct Node *prev = kNode->back;
    struct Node *front = kNode->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        return deleteHeadOfDoublyLinkedList(head);
    }
    else if (front == NULL)
    {
        return deleteTailOfDoublyLinkedList(head);
    }

    prev->next = front;
    front->back = prev;

    kNode->next = NULL;
    kNode->back = NULL;

    free(kNode);
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

    int k = 0;
    printf("Enter position of Node to delete: ");
    scanf("%d", &k);

    struct Node *head = ConvertArrayToDoublyLinkedList(arr, size);
    head = deleteKthElement(head, k);

    printf("Linked List: ");
    printLinkedList(head);

    freeLinkedList(head);

    printf("\n");
    return 0;
}
