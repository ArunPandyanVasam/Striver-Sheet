#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Queue structure using a linked list
typedef struct Queue
{
    Node *front, *rear;
    int size;
} Queue;

// Initialize queue
void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
    q->size = 0;
}

// Enqueue operation (add to rear)
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Dequeue operation (remove from front)
int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL; // Queue is empty

    free(temp);
    q->size--;
    return value;
}

// Get front element
int front(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->front->data;
}

// Stack structure using a queue
typedef struct Stack
{
    Queue q;
} Stack;

// Initialize stack
void initStack(Stack *s)
{
    initQueue(&s->q);
}

// Push operation using a queue
void push(Stack *s, int x)
{
    int size = s->q.size;
    enqueue(&s->q, x);
    for (int i = 0; i < size; i++)
    {
        enqueue(&s->q, dequeue(&s->q));
    }
}

// Pop operation (remove top element)
int pop(Stack *s)
{
    return dequeue(&s->q);
}

// Get top element
int top(Stack *s)
{
    return front(&s->q);
}

// Get stack size
int size(Stack *s)
{
    return s->q.size;
}


int main()
{
    Stack s;
    initStack(&s);

    push(&s, 3);
    push(&s, 2);
    push(&s, 4);
    push(&s, 1);

    printf("Top of the stack: %d\n", top(&s));
    printf("Size of the stack before removing element: %d\n", size(&s));
    printf("The deleted element is: %d\n", pop(&s));
    printf("Top of the stack after removing element: %d\n", top(&s));
    printf("Size of the stack after removing element: %d\n", size(&s));

    return 0;
}
