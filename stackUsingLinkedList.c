
#include <stdio.h>
#include <stdlib.h>

// Struct representing a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node with given data
Node *createNode(int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Struct to implement stack using a singly linked list
typedef struct Stack
{
    Node *head; // Pointer to the top of the stack
} Stack;

// Function to initialize the stack
void InitializeStack(Stack *stack)
{
    stack->head = NULL; // Stack starts empty
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->head == NULL; // Returns 1 if empty, 0 otherwise
}

// Function to push an element onto the stack
void push(Stack *stack, int new_data)
{
    // Create a new node with given data
    Node *new_node = createNode(new_data);

    // Check if memory allocation for the new node failed
    if (!new_node)
    {
        printf("\nStack Overflow\n");
        return;
    }

    // Link the new node to the current top node
    new_node->next = stack->head;

    // Update the top to the new node
    stack->head = new_node;
}

// Function to remove the top element from the stack
void pop(Stack *stack)
{
    // Check if the stack is empty (underflow condition)
    if (isEmpty(stack))
    {
        printf("\nStack Underflow\n");
        return;
    }

    // Assign the current top to a temporary variable
    Node *temp = stack->head;

    // Update the top to the next node
    stack->head = stack->head->next;

    // Free the memory of the old top node
    free(temp);
}

// Function to return the top element of the stack
int peek(Stack *stack)
{
    // Check if the stack is empty
    if (isEmpty(stack))
    {
        printf("\nStack is empty\n");
        return -1; // Return INT_MIN as an error indicator
    }

    return stack->head->data; // Return the top element
}

// Function to free all memory used by the stack (avoid memory leaks)
void freeStack(Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack); // Pop elements until stack is empty
    }
}

int main(void)
{
    // Creating a stack
    Stack stack;
    InitializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 11);
    push(&stack, 22);
    push(&stack, 33);
    push(&stack, 44);

    // Print top element of the stack
    printf("Top element is %d\n", peek(&stack));

    // Removing two elements from the top
    printf("Removing two elements: \n");
    pop(&stack);
    pop(&stack);

    // Print top element of the stack after popping
    printf("Top element is %d\n", peek(&stack));

    // Edge case: pop until the stack is empty
    pop(&stack);
    pop(&stack); // Stack is now empty

    // Attempt to pop from an empty stack
    pop(&stack); // Should print "Stack Underflow"

    // Attempt to peek from an empty stack
    printf("Top element is %d\n", peek(&stack)); // Should print "Stack is empty" and return INT_MIN

    // Free the stack memory before exiting
    freeStack(&stack);

    return 0;
}
