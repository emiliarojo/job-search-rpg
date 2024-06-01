#include <stdio.h>
#include <assert.h>
#include "../src/stack.h"

void test_stack_operations() {
    Stack stack;
    init_stack(&stack);

    // Test push operation
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    assert(stack.data[stack.top] == 3);

    // Test pop operation
    int value = pop(&stack);
    assert(value == 3);

    // Test is_stack_empty operation
    assert(!is_stack_empty(&stack));

    pop(&stack);
    pop(&stack);
    assert(is_stack_empty(&stack));

    printf("test_stack_operations passed.\n");
}

int main() {
    test_stack_operations();
    printf("All stack tests passed.\n");
    return 0;
}
