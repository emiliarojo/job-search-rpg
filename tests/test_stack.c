#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "stack.h"

void test_stack_operations(void) {
    Stack stack;
    initialize_stack(&stack, 10);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    CU_ASSERT_EQUAL(pop(&stack), 3);
    CU_ASSERT_EQUAL(pop(&stack), 2);
    CU_ASSERT_EQUAL(pop(&stack), 1);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Stack Suite", 0, 0);

    CU_add_test(suite, "test_stack_operations", test_stack_operations);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
