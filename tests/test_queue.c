#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "queue.h"

void test_queue_operations(void) {
    Queue queue;
    initialize_queue(&queue, 10);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    CU_ASSERT_EQUAL(dequeue(&queue), 1);
    CU_ASSERT_EQUAL(dequeue(&queue), 2);
    CU_ASSERT_EQUAL(dequeue(&queue), 3);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Queue Suite", 0, 0);

    CU_add_test(suite, "test_queue_operations", test_queue_operations);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
