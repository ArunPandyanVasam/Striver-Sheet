#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue *q, int value) {
    
}

int main(void) {

    return 0;
}