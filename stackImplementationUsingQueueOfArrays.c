#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue
{
    int arr[MAX];
    int front, rear, size;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue *q, int value)
{
    if (q->size == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q)
{
    if (q->size == 0)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
}

int front(Queue *q)
{
    if (q->size == 0)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->arr[q->front];
}

typedef struct Stack
{
    Queue q;
} Stack;

void initStack(Stack *s)
{
    initQueue(&s->q);
}

void push(Stack *s, int x)
{
    int size = s->q.size;
    enqueue(&s->q, x);
    for (int i = 0; i < size; i++)
    {
        enqueue(&s->q, dequeue(&s->q));
    }
}

int pop(Stack *s)
{
    return dequeue(&s->q);
}

int top(Stack *s)
{
    return front(&s->q);
}

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
