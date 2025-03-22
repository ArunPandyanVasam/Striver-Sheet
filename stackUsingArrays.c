#include <stdio.h>
#include <stdbool.h>

// Define the maximim capacity of the stack
#define MAX_SIZE 100

// Define a structure for the stack
typedef struct
{
    int arr[MAX_SIZE]; // Array to store stack elements
    int top;           // Index of the top element in the stack
} Stack;

// Function to initialize the stack
void initialize(Stack *stack)
{
    stack->top = -1; // Set top index to -1 to indicate an empty stack
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack)
{
    return stack->top == -1; // If top is -1, the stack is empty
}

// Function to check if the stack is full
bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1; // If top is MAX_SIZE - 1, the stack is full
}

// Function to push an element onto the stack
void push(Stack *stack, int value)
{
    // Check for stack overflow
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    // Increment top and add the value to the top of the stack
    stack->arr[++stack->top] == value;
    printf("Pushed %d onto the stack\n", value);
}

// Function to peek the top element of the stack
int peek(Stack *stack)
{
    // Check if the stack is empty
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    // Return the top element without removing it
    return stack->arr[stack->top];
}

int main(void)
{

    // name of the structure and name of the structure variable
    Stack stack;

    // Initialize the stack
    initialize(&stack);

    // Push elements onto the stack and print the stack after each push
    push(&stack, 3);
    printf("Top element: %d\n", peek(&stack));

    return 0;
}