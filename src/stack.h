#ifndef STACK_H
#define STACK_H

#include "tokenizer.h"
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    Token arr[MAX_SIZE];
    int top;
} Stack;

void initialize_stack(Stack *stack);

bool is_stack_empty(const Stack *stack);

bool is_stack_full(const Stack *stack);

void push(Stack *stack, Token token);

Token pop(Stack *stack);

Token peek_stack(const Stack *stack);

#endif
