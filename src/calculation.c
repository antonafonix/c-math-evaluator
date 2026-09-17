#include "calculation.h"
#include "queue.h"
#include "stack.h"
#include "tokenizer.h"

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_priority(char op) {
    if (op == '^')
        return 3;
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
            enqueue(output_queue, tokens[index]);
        } else if (TOKEN_OPERATOR == value_type) {
            while (operators_stack->top != -1 &&
                   get_priority(peek_stack(operators_stack).value.operator_char) >=
                       get_priority(tokens[index].value.operator_char)) {
                enqueue(output_queue, pop(operators_stack));
            }
            push(operators_stack, tokens[index]);
        } else if (TOKEN_LPAREN == value_type) {
            push(operators_stack, tokens[index]);
        } else if (TOKEN_RPAREN == value_type) {
            while (!is_stack_empty(operators_stack) &&
                   peek_stack(operators_stack).type != TOKEN_LPAREN) {
                enqueue(output_queue, pop(operators_stack));
            }
            if (is_stack_empty(operators_stack)) {
                printf("Error stack is empty!\n");
                return;
            } else {
                pop(operators_stack);
            }
        }

        index++;
    }

    while (operators_stack->top != -1) {
        enqueue(output_queue, pop(operators_stack));
    }
}

double calculate_postfix(Token *tokens, int size) {
    Stack operators_stack;
    Queue output_queue;

    initialize_stack(&operators_stack);
    initialize_queue(&output_queue);

    to_postfix(tokens, size, &output_queue, &operators_stack);

    printQueue(&output_queue);

    double result = 0;

    Stack result_stack;

    initialize_stack(&result_stack);

    for (int i = output_queue.front; i < output_queue.rear; i++) {
        if (output_queue.items[i].type == TOKEN_NUMBER) {
            push(&result_stack, output_queue.items[i]);
        } else {
            Token popped_second_number = pop(&result_stack);
            double second_number = popped_second_number.value.number_value;
            Token popped_first_number = pop(&result_stack);
            double first_number = popped_first_number.value.number_value;

            switch (output_queue.items[i].value.operator_char) {
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
            case '^':
                result = pow(first_number, second_number);
                break;
            default:
                return -1;
            }
            Token token_result;
            token_result.type = TOKEN_NUMBER;
            token_result.value.number_value = result;
            push(&result_stack, token_result);
        }
    }

    Token popped_result = pop(&result_stack);

    return popped_result.value.number_value;
}