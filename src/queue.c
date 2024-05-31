#include <stdlib.h>
#include "queue.h"

// Function to initialize the queue
void init_queue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

// Function to add an element to the queue
void enqueue(Queue *queue, int value) {
    queue->data[++queue->rear] = value;
}

// Function to remove an element from the queue
int dequeue(Queue *queue) {
    return queue->data[queue->front++];
}

// Function to check if the queue is empty
int is_empty(Queue *queue) {
    return queue->front > queue->rear;
}
