#include <stdio.h>
#include <stdlib.h>

// Define Node structure using typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define Stack using typedef
typedef struct {
    Node* top;
} Stack;

// Define Queue using typedef
typedef struct {
    Stack input;
    Stack output;
} Queue;

// Initialize a stack
void initStack(Stack* s) {
    s->top = NULL;
}

// Push operation
void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop operation
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = temp->next;
    free(temp);
    return poppedValue;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Get top element
int top(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->top->data;
}

// Initialize queue
void initQueue(Queue* q) {
    initStack(&q->input);
    initStack(&q->output);
}

// Enqueue (Push) operation
void enqueue(Queue* q, int data) {
    while (!isEmpty(&q->input)) {
        push(&q->output, pop(&q->input));
    }
    printf("The element pushed is %d\n", data);
    push(&q->input, data);
    while (!isEmpty(&q->output)) {
        push(&q->input, pop(&q->output));
    }
}

// Dequeue (Pop) operation
int dequeue(Queue* q) {
    if (isEmpty(&q->input)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return pop(&q->input);
}

// Get front element
int front(Queue* q) {
    if (isEmpty(&q->input)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return top(&q->input);
}

// Get queue size
int size(Queue* q) {
    Node* temp = q->input.top;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("The element popped is %d\n", dequeue(&q));
    enqueue(&q, 5);
    printf("The front of the queue is %d\n", front(&q));
    printf("The size of the queue is %d\n", size(&q));

    return 0;
}
