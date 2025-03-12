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

// insert before head
struct Node *insertBeforeHead(struct Node *head, int value)
{
    struct Node *newHead = createNode(value);
    newHead->next = head;

    if (head != NULL)
    {
        head->back = newHead;
    }

    return newHead;
}

// insert before tail
struct Node *insertBeforeTail(struct Node *head, int value)
{
    if (head->next == NULL)
    {
        return insertBeforeHead(head, value);
    }

    struct Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    struct Node *prev = tail->back;
    struct Node *newNode = createNode(value);

    newNode->back = prev;
    newNode->next = tail;

    tail->back = newNode;
    prev->next = newNode;

    return head;
}

// insert before Kth element
struct Node* insertBeforeKthNode(struct Node* head, int value, int k) {

    if (k <= 0) {
        printf("Invalid value of k: %d\n", k);
        return head;
    }

    if (k == 1) {
        return insertBeforeHead(head, value);
    }

    struct Node* temp = head;
    int ctr = 0;

    while (temp != NULL) {
        ctr++;
        if (ctr == k) break;
        temp = temp->next;
    }

    // If k is out of bounds
    if (temp == NULL) {
        printf("Invalid position: k = %d is greater than list length\n", k);
        return head;
    }

    struct Node* prev =temp->back;
    struct Node* newNode = createNode(value);
    
    newNode->back = prev;
    newNode->next = temp;


    prev->next = newNode;
    temp->back = newNode;

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

    printf("Initial Linked List: ");
    printLinkedList(head);

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    int k;
    printf("Enter value of k (1 to N): ");
    scanf("%d", &k);

    head = insertBeforeKthNode(head, value, k);

    printf("Updated Linked List: ");
    printLinkedList(head);

    freeLinkedList(head);

    printf("\n");
    return 0;
}