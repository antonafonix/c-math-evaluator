#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack);

bool is_empty(Stack *stack);

bool is_full(Stack *stack);

void push(Stack *stack, int value);

int pop(Stack *stack);

int peek(Stack *stack);

#endif
