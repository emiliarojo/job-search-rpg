#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100 // Maximum size of the queue

// Definition of the Queue structure
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void init_queue(Queue *queue);

// Function to add an element to the queue
void enqueue(Queue *queue, int value);

// Function to remove an element from the queue
int dequeue(Queue *queue);

// Function to check if the queue is empty
int is_empty(Queue *queue);

#endif // QUEUE_H
