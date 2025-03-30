#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define a max size for stacks

// Structure for Stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int data) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

// Function to get the top element of the stack
int top(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return s->arr[s->top];
}

// Structure for Queue using two stacks
struct Queue {
    struct Stack input;
    struct Stack output;
};

// Function to initialize a queue
void initQueue(struct Queue *q) {
    initStack(&q->input);
    initStack(&q->output);
}

// Function to push an element into the queue
void enqueue(struct Queue *q, int data) {
    while (!isEmpty(&q->input)) {
        push(&q->output, pop(&q->input));
    }
    printf("The element pushed is %d\n", data);
    push(&q->input, data);
    while (!isEmpty(&q->output)) {
        push(&q->input, pop(&q->output));
    }
}

// Function to pop an element from the queue
int dequeue(struct Queue *q) {
    if (isEmpty(&q->input)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return pop(&q->input);
}

// Function to get the front element of the queue
int front(struct Queue *q) {
    if (isEmpty(&q->input)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return top(&q->input);
}

// Function to get the size of the queue
int size(struct Queue *q) {
    return q->input.top + 1;
}

int main() {
    struct Queue q;
    initQueue(&q);
    
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("The element popped is %d\n", dequeue(&q));
    enqueue(&q, 5);
    printf("The top of the queue is %d\n", front(&q));
    printf("The size of the queue is %d\n", size(&q));
    
    return 0;
}
