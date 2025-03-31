#include <stdio.h>
#include <stdlib.h>

// Define stack node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define stack structure
typedef struct {
    Node* top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = NULL;
}

// Push element onto stack
void push(Stack *s, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop element from stack
int pop(Stack *s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = temp->next;
    free(temp);
    return poppedValue;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == NULL;
}

// Define queue using two stacks
typedef struct {
    Stack input, output;
} MyQueue;

// Initialize queue
void initQueue(MyQueue *q) {
    initStack(&q->input);
    initStack(&q->output);
}

// Push element to queue
void queuePush(MyQueue *q, int x) {
    printf("The element pushed is %d\n", x);
    push(&q->input, x);
}

// Pop element from queue
int queuePop(MyQueue *q) {
    if (isEmpty(&q->output)) {
        while (!isEmpty(&q->input)) {
            push(&q->output, pop(&q->input));
        }
    }
    return pop(&q->output);
}

// Get front element of queue
int queueTop(MyQueue *q) {
    if (isEmpty(&q->output)) {
        while (!isEmpty(&q->input)) {
            push(&q->output, pop(&q->input));
        }
    }
    return q->output.top->data;
}

// Get size of queue
int queueSize(MyQueue *q) {
    int count = 0;
    Node* temp = q->input.top;
    while (temp) {
        count++;
        temp = temp->next;
    }
    temp = q->output.top;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    MyQueue q;
    initQueue(&q);
    
    queuePush(&q, 3);
    queuePush(&q, 4);
    printf("The element popped is %d\n", queuePop(&q));
    queuePush(&q, 5);
    printf("The top of the queue is %d\n", queueTop(&q));
    printf("The size of the queue is %d\n", queueSize(&q));
    
    return 0;
}
