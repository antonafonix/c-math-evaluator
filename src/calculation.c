#include "calculation.h"
#include "queue.h"
#include "stack.h"
#include "tokenizer.h"

#include <ctype.h>
#include <stdbool.h>
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

void to_postfix(Token *tokens, int size, Queue *output_queue, Stack *operators_stack) {
    int index = 0;
    while (index < size) {
        TokenType value_type = tokens[index].type;

        if (TOKEN_NUMBER == value_type) {
            enqueue(output_queue, tokens[index].value.number_value);
        } else if (TOKEN_OPERATOR == value_type) {
            while (operators_stack->top != -1 &&
                   get_priority(peek_stack(operators_stack)) >=
                       get_priority(tokens[index].value.operator_char)) {
                char op2 = pop(operators_stack);
                enqueue(output_queue, op2);
                printf("added %c to the output queue\n", op2);
            }

            push(operators_stack, tokens[index].value.operator_char);
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

    int result = 0;

    Stack number_stack;

    initialize_stack(&number_stack);

    for (int i = output_queue.front + 1; i < output_queue.rear; i++) {
        if (isdigit(output_queue.items[i])) {
            push(&number_stack, output_queue.items[i] - '0');
        } else {
            int second_number = pop(&number_stack);
            int first_number = pop(&number_stack);
            switch (output_queue.items[i]) {
            case '+':
                result = first_number + second_number;
                break;
            case '*':
                result = first_number * second_number;
                break;
            case '/':
                if (second_number == 0) {
                    printf("Error! You cannot divide by 0\n");
                    return 0;
                } else {
                    result = first_number / second_number;
                }
                break;
            case '-':
                result = first_number - second_number;
                break;
            default:
                return -1;
            }
            push(&number_stack, result);
        }
    }

    return pop(&number_stack);
}