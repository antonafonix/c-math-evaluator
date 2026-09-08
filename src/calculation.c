#include "calculation.h"
#include "stack.h"
#include "tokenizer.h"
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_priority(char op) {
    if (op == '*' || op == '/')
        return 3;
    if (op == '+' || op == '-')
        return 2;
    return 0;
}

int calculate(Token *tokens, int size) {
    Stack operators_stack;
    Queue numbers_queue;

    initialize_stack(&operators_stack);
    initialize_queue(&numbers_queue);

    int index = 0;
    while (index < size) {
        TokenType value_type = tokens[index].type;
        int value = tokens[index].type;
        if (TOKEN_NUMBER == value_type) {
            push(&numbers_queue, atoi(tokens[index].value));
        } 

        index++;
    }

    int result = pop(&solving_stack);
    return result;
}
