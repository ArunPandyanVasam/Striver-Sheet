#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node structure representing a single node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) // Check memory allocation failure
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Structure to implement queue operations using a linked list
typedef struct Queue
{
    Node *front, *rear;
    int size; // Variable to keep track of the queue size
} Queue;

// Function to create a queue
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q) // Check memory allocation failure
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    q->size = 0; // Initialize size to 0
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->size == 0; // Returns 1 if empty, 0 otherwise
}

// Function to return the size of the queue
int getSize(Queue *q)
{
    return q->size;
}

// Function to add an element to the queue
void enqueue(Queue *q, int new_data)
{
    // Create a new linked list node
    Node *new_node = createNode(new_data);
    if (!new_node)
    {
        printf("Queue Overflow\n");
        return;
    }

    // If queue is empty, the new node is both the front and rear
    if (q->rear == NULL)
    {
        q->front = q->rear = new_node;
    }
    else
    {
        // Add the new node at the end of the queue and change rear
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++; // Increase queue size
}

// Function to remove an element from the queue
void dequeue(Queue *q)
{
    // If queue is empty, return
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return;
    }

    // Store previous front and move front one node ahead
    Node *temp = q->front;
    q->front = q->front->next;

    // If front becomes null, then change rear also to null
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    // Deallocate memory of the old front node
    free(temp);

    q->size--; // Decrease queue size
}

// Function to return the front element of the queue
int getFront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->front->data;
}

// Function to return the rear element of the queue
int getRear(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->rear->data;
}

// Function to free all memory used by the queue (prevent memory leaks)
void freeQueue(Queue *q)
{
    while (!isEmpty(q))
    {
        dequeue(q);
    }
    free(q); // Free the queue structure itself
}

int main(void)
{
    Queue *q = createQueue();
    if (!q) // Check if queue creation failed
    {
        return 1;
    }

    // Enqueue elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);

    // Print queue size, front, and rear elements
    printf("Queue Size: %d\n", getSize(q));
    printf("Queue Front: %d\n", getFront(q));
    printf("Queue Rear: %d\n", getRear(q));

    // Dequeue elements from the queue
    dequeue(q);
    dequeue(q);

    // Edge case: Dequeue from empty queue
    dequeue(q); // Should print "Queue Underflow"

    // Edge case: Getting front/rear from an empty queue
    printf("Queue Size: %d\n", getSize(q));  // Should print 0
    printf("Queue Front: %d\n", getFront(q)); // Should print "Queue is empty"
    printf("Queue Rear: %d\n", getRear(q));   // Should print "Queue is empty"

    // Enqueue more elements
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Print queue size
    printf("Queue Size: %d\n", getSize(q));

    // Dequeue an element
    dequeue(q);

    // Print front, rear, and size after more operations
    printf("Queue Size: %d\n", getSize(q));
    printf("Queue Front: %d\n", getFront(q));
    printf("Queue Rear: %d\n", getRear(q));

    // Free memory before exiting
    freeQueue(q);

    return 0;
}
