#include <stdio.h>
#include <assert.h>
#include "../src/queue.h"

void test_queue_operations() {
    Queue queue;
    init_queue(&queue);

    // Test enqueue operation
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    assert(queue.data[queue.rear] == 3);

    // Test dequeue operation
    int value = dequeue(&queue);
    assert(value == 1);

    // Test is_empty operation
    assert(!is_empty(&queue));

    dequeue(&queue);
    dequeue(&queue);
    assert(is_empty(&queue));

    printf("test_queue_operations passed.\n");
}

int main() {
    test_queue_operations();
    printf("All queue tests passed.\n");
    return 0;
}
