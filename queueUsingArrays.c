#include <stdio.h>
#include <stdbool.h>

// Define the maximum capacity of the queue
#define MAX_SIZE 100

// Defining the Queue structure
typedef struct
{
    int items[MAX_SIZE]; // Array to store queue elements
    int front;           // Index of the front element
    int rear;            // Index where the next element will be inserted
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q)
{
    q->front = 0; // Front starts at index 0
    q->rear = 0;  // Rear starts at index 0, meaning the queue is empty
}

// Function to check if the queue is empty
bool isEmpty(Queue *q)
{
    return (q->front == q->rear); // If front and rear are the same, queue is empty
}

// Function to check if the queue is full
bool isFull(Queue *q)
{
    return (q->rear == MAX_SIZE); // If rear reaches MAX_SIZE, queue is full
}

// Function to add an element to the queue (Enqueue operation)
void enqueue(Queue *q, int value)
{
    if (isFull(q)) // Check if the queue is full
    {
        printf("Queue is full\n");
        return;
    }
    q->items[q->rear] = value; // Insert value at the rear position
    q->rear++;                 // Move rear forward
}

// Function to remove an element from the queue (Dequeue operation)
void dequeue(Queue *q)
{
    if (isEmpty(q)) // Check if the queue is empty
    {
        printf("Queue is empty - dequeue function\n");
        return;
    }
    q->front++; // Move front forward to remove the element

    // If queue becomes empty after dequeuing, reset it
    if (q->front == q->rear)
    {
        q->front = 0;
        q->rear = 0;
    }
}

// Function to get the element at the front of the queue (Peek operation)
int peek(Queue *q)
{
    if (isEmpty(q)) // Check if queue is empty
    {
        printf("Queue is empty - peek function\n");
        return -1; // Return -1 as an indicator of empty queue
    }
    return q->items[q->front]; // Return the front element
}

// Function to print the current queue
void printQueue(Queue *q)
{
    if (isEmpty(q)) // Check if queue is empty
    {
        printf("Queue is empty - printQueue function\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front; i < q->rear; i++) // Loop through queue elements
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main(void)
{
    Queue q;              // Declare a queue
    initializeQueue(&q);  // Initialize the queue

    // Enqueue elements
    enqueue(&q, 10);
    printQueue(&q);

    enqueue(&q, 20);
    printQueue(&q);

    enqueue(&q, 30);
    printQueue(&q);

    // Peek front element
    printf("Front element: %d\n", peek(&q));

    // Dequeue an element
    dequeue(&q);
    printQueue(&q);

    // Peek front element after dequeue
    printf("Front element after dequeue-1: %d\n", peek(&q));

    // Edge case: Dequeuing until the queue becomes empty
    dequeue(&q);
    printQueue(&q);

    // Peek front element after dequeue
    printf("Front element after dequeue-2: %d\n", peek(&q));

    dequeue(&q);
    printQueue(&q);

    // Peek front element after dequeue
    printf("Front element after dequeue-3: %d\n", peek(&q));

    // Edge case: Attempt to dequeue from an empty queue
    dequeue(&q);

    return 0;
}
