#include <assert.h>
#include "queue.h"

void test_queue() {
    Queue queue;
    init_queue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    assert(dequeue(&queue) == 1);
    assert(dequeue(&queue) == 2);
    assert(is_empty(&queue) == 1);
}

int main() {
    test_queue();
    printf("All tests passed.\n");
    return 0;
}
