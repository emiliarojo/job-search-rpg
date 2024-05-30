#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int is_empty(Queue *queue);

#endif
