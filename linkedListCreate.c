#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
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
    return newNode;
}

// Function to convert an array to a linked list
struct Node *ConvertArrayToLinkedList(int arr[], int size)
{

    if (size == 0)
    {
        return NULL;
    }

    struct Node *head = createNode(arr[0]);
    struct Node *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

int lengthOfSingleLinkedList(struct Node *head) {
    int ctr = 0;
    struct Node *temp = head;
    while (temp)
    {
        ctr++;
        temp = temp->next;
    }
    return ctr;
}

int checkIfPresented(struct Node *head, int searchValue) {
    struct Node *temp = head;
    while (temp)
    {
        if (temp->data == searchValue) return 1;
        temp = temp->next;
    }
    return 0;
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

    struct Node *head = ConvertArrayToLinkedList(arr, size);

    int searchValue = 0;
    printf("Enter the value to search: ");
    scanf("%d", &searchValue);

    printf("(1 - Found | 0 - Not Found) -> %d\n", checkIfPresented(head, searchValue));

    printf("Length of LinkedList: %d\n", lengthOfSingleLinkedList(head));

    printf("Linked List: ");
    printLinkedList(head);

    freeLinkedList(head);

    printf("\n");
    return 0;
}
