#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode *next;
} stackNode;

typedef struct stack {
    stackNode *top;
    int size;
} stack;

void initStack(stack *s) {
    s->top = NULL;
    s->size = 0;
}

void stackPush(stack *s, int x) {
    stackNode *element = (stackNode *)malloc(sizeof(stackNode));
    if (element == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    element->data = x;
    element->next = s->top;
    s->top = element;
    s->size++;
    printf("Element pushed: %d\n", x);
}

int stackPop(stack *s) {
    if (s->top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1; // Stack is empty
    }
    int topData = s->top->data;
    stackNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return topData;
}

int stackSize(stack *s) {
    return s->size;
}

int stackIsEmpty(stack *s) {
    return s->top == NULL;
}

int stackPeek(stack *s) {
    if (s->top == NULL) {
        return -1; // Stack is empty
    }
    return s->top->data;
}

void printStack(stack *s) {
    stackNode *current = s->top;
    if (current == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    stack s;
    initStack(&s);

    stackPush(&s, 10);
    stackPush(&s, 20);
    stackPush(&s, 30);

    printStack(&s);

    printf("Element popped: %d\n", stackPop(&s));
    printf("Stack size: %d\n", stackSize(&s));
    printf("Is stack empty? %s\n", stackIsEmpty(&s) ? "Yes" : "No");
    printf("Stack's top element: %d\n", stackPeek(&s));

    // Edge Case: Trying to pop from an empty stack
    stackPop(&s);  // Pop remaining elements
    stackPop(&s);
    printf("Element popped from empty stack: %d\n", stackPop(&s)); // This will cause underflow

    return 0;
}
