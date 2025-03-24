#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int start, end, currSize, maxSize;
} Queue;

void initQueue(Queue *q, int maxSize) {
    q->arr = (int *)malloc(sizeof(int) * maxSize);
    if (!q->arr) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    q->maxSize = maxSize;
    q->start = -1;
    q->end = -1;
    q->currSize = 0;
}

void push(Queue *q, int newElement) {
    if (q->currSize == q->maxSize) {
        printf("Queue is full\nExiting...\n");
        exit(1); // Exit if the queue is full
    }
    if (q->end == -1) {
        q->start = 0;
        q->end = 0;
    } else {
        q->end = (q->end + 1) % q->maxSize;
    }
    q->arr[q->end] = newElement;
    printf("The element pushed is %d\n", newElement);
    q->currSize++;
}

int pop(Queue *q) {
    if (q->start == -1) {
        printf("Queue Empty\nExiting...\n");
        exit(1); // Exit if the queue is empty
    }
    int popped = q->arr[q->start];
    if (q->currSize == 1) {
        q->start = -1;
        q->end = -1;
    } else {
        q->start = (q->start + 1) % q->maxSize;
    }
    q->currSize--;
    return popped;
}

int top(Queue *q) {
    if (q->start == -1) {
        printf("Queue is Empty\n");
        exit(1); // Exit if the queue is empty
    }
    return q->arr[q->start];
}

int size(Queue *q) {
    return q->currSize;
}

int main() {
    Queue q;
    initQueue(&q, 6); // Initialize queue with maxSize 6

    push(&q, 4);
    push(&q, 14);
    push(&q, 24);
    push(&q, 34);

    printf("The peek of the queue before deleting any element: %d\n", top(&q));
    printf("The size of the queue before deletion: %d\n", size(&q));

    printf("The first element to be deleted: %d\n", pop(&q));

    printf("The peek of the queue after deleting an element: %d\n", top(&q));
    printf("The size of the queue after deleting an element: %d\n", size(&q));

    return 0;
}
