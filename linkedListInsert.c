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

//  insert value at head
struct Node* insertElementAtHead(struct Node* head, int value) {

    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

//  insert value at tail
struct Node* insertElementAtTail(struct Node* head, int value) {

    if (head == NULL) {
        struct Node* newNode = createNode(value);
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
    {
       temp = temp->next;
    }
    struct Node* newNode = createNode(value);
    temp->next = newNode;
    return head;
}

// insert value at a given position;
struct Node* insertValueAtGivenPosition(struct Node* head, int value, int position) {

    if (head == NULL) {
        if (position == 1) {
            head = createNode(value);
        } else {
            printf("List is empty, so position should be 1");
            return head;
        }
    } 

    if (position == 1) {
        struct Node* newNode = createNode(value);
        newNode->next = head;
        return newNode;
    }

    int ctr = 0; 
    struct Node* temp = head;
    while (temp != NULL)
    {
        ctr++;
        if (ctr == (position-1)) {
            struct Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;

}

// insert value before a given number
struct Node* insertValueBeforeGivenNumber(struct Node* head, int element, int value) {

    if (head == NULL) {
        return NULL;
    } 

    if (head->data == value) {
        struct Node* newNode = createNode(element);
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == value) {
            struct Node* newNode = createNode(element);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
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

    int element = 0;
    printf("Enter the element to insert: ");
    scanf("%d", &element);

    int value = 0;
    printf("12 -> 5 -> 7 -> 8\n");
    printf("Enter a value from list, where element has to insert before: ");
    scanf("%d", &value);

    // Delete Node at Position
    head = insertValueBeforeGivenNumber(head, element, value);

    // Print LinkedList
    printLinkedList(head);

    // Free Memory
    freeLinkedLIst(head);

    printf("\n");
    return 0;
}