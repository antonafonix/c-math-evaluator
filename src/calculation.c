#include "calculation.h"
#include "queue.h"
#include "stack.h"
#include "tokenizer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_priority(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void to_postfix(Token *tokens, int size, Queue* output_queue, Stack* operators_stack) {
    int index = 0;
    while (index < size) {
        char value = tokens[index].value[0];
        TokenType value_type = tokens[index].type;

        if (TOKEN_NUMBER == value_type) {
            enqueue(output_queue, value);
        } else if (TOKEN_OPERATOR == value_type) {

            while (operators_stack->top != -1 &&
                   get_priority(peek_stack(operators_stack)) >= get_priority(value)) {
                char op2 = pop(operators_stack);
                enqueue(output_queue, op2);
                printf("added %c to the output queue\n", op2);
            }

            push(operators_stack, value);
        }

        index++;
    }

    while (operators_stack->top != -1) {
        char op2 = pop(operators_stack);
        enqueue(output_queue, op2);
    }
}

int calculate_postfix(Token *tokens, int size) {
    Stack operators_stack;
    Queue output_queue;

    initialize_stack(&operators_stack);
    initialize_queue(&output_queue);

    to_postfix(tokens, size, &output_queue, &operators_stack);

    printQueue(&output_queue);

    return 0;
}