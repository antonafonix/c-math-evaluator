#include "stack.h"
#include "tokenizer.h"
#include <stdbool.h>
#include <stdio.h>

void initialize_stack(Stack *stack) { stack->top = -1; }

bool is_stack_empty(const Stack *stack) { return stack->top == -1; }

bool is_stack_full(const Stack *stack) { return stack->top >= MAX_SIZE - 1; }

void push(Stack *stack, Token token) {
    if (is_stack_full(stack)) {
        printf("Stack overflow\n");
        return;
    }

    stack->arr[++stack->top] = token;
}

Token pop(Stack *stack) {
    if (is_stack_empty(stack)) {
        printf("Stack is empty\n");

        Token empty = {0};
        empty.type = TOKEN_EOF;
        return empty;
    }

    return stack->arr[stack->top--];
}

Token peek_stack(const Stack *stack) {
    if (is_stack_empty(stack)) {
        printf("Stack is empty\n");

        Token empty = {0};
        empty.type = TOKEN_EOF;
        return empty;
    }

    return stack->arr[stack->top];
}