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

// remove Head
struct Node* removeHead(struct Node *head)
{
    if (head == NULL)
        return head;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// remove Node at a position - including head, tail, position
struct Node* removeNodeAtPosition(struct Node* head, int target) {

    if (head == NULL) return head;
    if (target == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int ctr = 0; 
    struct Node* current = head; 
    struct Node* previous = NULL;
    while (current != NULL)
    {
        ctr++;
        if (ctr == target && previous != NULL) {
            previous->next = previous->next->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;   
    }
    return head;
}

// remove Tail
struct Node* removeTail (struct Node* head) {
    if (head == NULL || head->next == NULL) return NULL;

    struct Node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
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

    int target = 0;
    printf("Enter the position of Node to delete in a linked list: ");
    scanf("%d", &target);

    // Delete Node at Position
    head = removeNodeAtPosition(head, target);

    // Print LinkedList
    printLinkedList(head);

    // Free Memory
    freeLinkedLIst(head);

    printf("\n");
    return 0;
}