#include <stdio.h>
#include <stdlib.h>

// Define a QueueNode struct to hold the data and next pointer
typedef struct QueueNode {
    int val;
    struct QueueNode* next;
} QueueNode;

// Define a Queue struct to hold the Front and Rare pointers and size
typedef struct Queue {
    QueueNode* front;
    QueueNode* rare;
    int size;
} Queue;

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to peek at the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->front->val;
}

// Function to enqueue a new element into the queue
void enqueue(Queue* q, int value) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        printf("Queue is Full\n");
        return;
    }
    temp->val = value;
    temp->next = NULL;

    if (q->front == NULL) {
        q->front = temp;
        q->rare = temp;
    } else {
        q->rare->next = temp;
        q->rare = temp;
    }
    printf("%d Inserted into Queue\n", value);
    q->size++;
}

// Function to dequeue an element from the queue
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return;
    }
    QueueNode* temp = q->front;
    printf("%d Removed From Queue\n", q->front->val);
    q->front = q->front->next;
    free(temp);
    q->size--;
}

// Function to print the current size of the queue
int getSize(Queue* q) {
    return q->size;
}

// Main function
int main() {
    Queue q;
    q.front = NULL;
    q.rare = NULL;
    q.size = 0;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    
    dequeue(&q);

    printf("The size of the Queue is %d\n", getSize(&q));
    printf("The Peek element of the Queue is %d\n", peek(&q));

    return 0;
}
