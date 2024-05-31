#include <stdlib.h>
#include "stack.h"

// Function to initialize the stack
void init_stack(Stack *stack) {
    stack->top = -1;
}

// Function to push a value onto the stack
void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

// Function to pop a value from the stack
int pop(Stack *stack) {
    return stack->data[stack->top--];
}

// Function to check if the stack is empty
int is_stack_empty(Stack *stack) {
    return stack->top == -1;
}
