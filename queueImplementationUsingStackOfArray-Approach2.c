#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Push element onto stack
void push(Stack *s, int x) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = x;
}

// Pop element from stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
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
    return q->output.arr[q->output.top];
}

// Get size of queue
int queueSize(MyQueue *q) {
    return (q->input.top + 1) + (q->output.top + 1);
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
