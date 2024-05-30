#include <assert.h>
#include "stack.h"

void test_stack() {
    Stack stack;
    init_stack(&stack);
    push(&stack, 1);
    push(&stack, 2);
    assert(pop(&stack) == 2);
    assert(pop(&stack) == 1);
    assert(is_stack_empty(&stack) == 1);
}

int main() {
    test_stack();
    printf("All tests passed.\n");
    return 0;
}
