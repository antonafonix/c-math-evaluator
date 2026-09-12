#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

void initialize_stack(Stack *stack) { stack->top = -1; }

bool is_stack_empty(const Stack *stack) { return stack->top == -1; }

bool is_stack_full(const Stack *stack) { return stack->top >= MAX_SIZE - 1; }

void push(Stack *stack, int value) {
    if (is_stack_full(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_stack_empty(stack)) {
        printf("stack is empty\n");
        return -1;
    }
    int popped = stack->arr[stack->top];
    stack->top--;
    return popped;
}

int peek_stack(Stack *stack) {
    if (is_stack_empty(stack)) {
        printf("stack is empty\n");
        return -1;
    }

    return stack->arr[stack->top];
}
