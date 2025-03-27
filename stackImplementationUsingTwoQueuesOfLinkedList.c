#include <stdio.h>
#include <stdlib.h>

// Define a Queue Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Queue
typedef struct Queue {
    Node *front, *rear;
    int size;
} Queue;

// Function to initialize a queue
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->size--;
    return value;
}

// Function to get the front element
int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return q->front->data;
}

// Define a Stack using two Queues
typedef struct Stack {
    Queue q1, q2;
} Stack;

// Function to initialize a stack
void initStack(Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Function to push an element into the stack
void push(Stack *s, int x) {
    enqueue(&s->q2, x);

    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap the names of q1 and q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

// Function to get the top element of the stack
int top(Stack *s) {
    return front(&s->q1);
}

// Function to get the size of the stack
int size(Stack *s) {
    return s->q1.size;
}

// Function to free all allocated memory
void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}


int main() {
    Stack s;
    initStack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("Current size: %d\n", size(&s));
    printf("Top element: %d\n", top(&s));
    pop(&s);
    printf("Top element after pop: %d\n", top(&s));
    pop(&s);
    printf("Top element after another pop: %d\n", top(&s));

    printf("Current size: %d\n", size(&s));

    // Free dynamically allocated memory
    freeQueue(&s.q1);
    freeQueue(&s.q2);

    return 0;
}
