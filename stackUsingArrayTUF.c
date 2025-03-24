#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int size;
    int *arr;
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->size = 1000;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    if (s->arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit the program if memory allocation fails
    }
}

void push(Stack *s, int x) {
    if (s->top == s->size - 1) {
        printf("Stack Overflow! Cannot push %d\n", x);
        return; // Stack overflow, do not push
    }
    s->top++;
    s->arr[s->top] = x;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        return -1; // Stack underflow, return error value
    }
    int x = s->arr[s->top];
    s->top--;
    return x;
}

int top(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty! Cannot access top\n");
        return -1; // Return error value if stack is empty
    }
    return s->arr[s->top];
}

int size(Stack *s) {
    return s->top + 1;
}

void freeStack(Stack *s) {
    free(s->arr);
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 6);
    push(&s, 3);
    push(&s, 7);

    printf("Top of stack before deleting any element: %d\n", top(&s));
    printf("Size of stack before deleting any element: %d\n", size(&s));
    printf("The element deleted is: %d\n", pop(&s));
    printf("Size of stack after deleting an element: %d\n", size(&s));
    printf("Top of stack after deleting an element: %d\n", top(&s));

    // Edge Case: Try popping from an empty stack
    pop(&s);
    pop(&s); // Now the stack is empty
    printf("Trying to pop from an empty stack: %d\n", pop(&s));

    freeStack(&s);
    return 0;
}
