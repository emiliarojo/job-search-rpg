#include <stdlib.h>
#include "stack.h"

void init_stack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    return stack->data[stack->top--];
}

int is_stack_empty(Stack *stack) {
    return stack->top == -1;
}
