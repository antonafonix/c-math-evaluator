#include "stack.h"
#include <stdbool.h>
#include <stdio.h>

void initialize_stack(Stack *stack) { stack->top = -1; }

bool is_empty(Stack *stack) { return stack->top == -1; }

bool is_full(Stack *stack) { return stack->top >= MAX_SIZE - 1; }

void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("stack is empty\n");
        return -1;
    }
    int popped = stack->arr[stack->top];
    stack->top--;
    printf("popped %d from the stack\n", popped);
    return popped;
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("stack is empty\n");
        return -1;
    }

    return stack->arr[stack->top];
}
