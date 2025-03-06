#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

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

struct Node *removeHead(struct Node *head)
{
    if (head == NULL)
        return head;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

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

    head = removeHead(head);

    // Print LinkedList
    printLinkedList(head);

    // Free Memory
    freeLinkedLIst(head);

    printf("\n");
    return 0;
}