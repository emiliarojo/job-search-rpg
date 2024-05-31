#ifndef STACK_H
#define STACK_H

#define MAX_STACK_SIZE 100 // Maximum size of the stack

// Definition of the Stack structure
typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void init_stack(Stack *stack);

// Function to push a value onto the stack
void push(Stack *stack, int value);

// Function to pop a value from the stack
int pop(Stack *stack);

// Function to check if the stack is empty
int is_stack_empty(Stack *stack);

#endif
