#include <stdio.h>
#include <stdlib.h>

// Structure
struct Node
{
    int data;
    struct Node *next;
};

// Create Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("memory allocation is failed.\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// convert from Array To LinkedList
struct Node *convertArrayToLinkedList(int arr[], int size)
{

    if (size == 0)
    {
        return NULL;
    }

    struct Node *head = createNode(arr[0]);
    struct Node *temp = head;

    for (int i = 1; i < size; i++)
    {
        temp->next = createNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

struct Node* insertElement(struct Node* head, int value) {

    struct Node* temp = createNode(value);
    temp->next = head;
    return temp;
}



// print LinkedList
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

// free LinkedList  
void freeLinkedLIst(struct Node *head)
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

    int arr[] = {12, 5, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct Node *head = convertArrayToLinkedList(arr, size);

    int value = 0;
    printf("Enter the value to insert at head of node: ");
    scanf("%d", &value);

    // Delete Node at Position
    head = insertElement(head, value);

    // Print LinkedList
    printLinkedList(head);

    // Free Memory
    freeLinkedLIst(head);

    printf("\n");
    return 0;
}