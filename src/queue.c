#include <stdlib.h>
#include "queue.h"

void init_queue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

void enqueue(Queue *queue, int value) {
    queue->data[++queue->rear] = value;
}

int dequeue(Queue *queue) {
    return queue->data[queue->front++];
}

int is_empty(Queue *queue) {
    return queue->front > queue->rear;
}
