#include "calculation.h"
#include "stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int is_number(const char *value) {
    if (value == NULL || value[0] == '\0')
        return 0;

    int dot_counter = 0;
    size_t length = 1;

    for (char character = value[1]; character != '\0'; ++length, character = value[length]) {
        int const is_valid_character =
            (character >= '0' && character <= '9') || (character == '.' && ++dot_counter == 1);

        if (is_valid_character == 0) {
            return 0;
        }
    }

    char const first_character = value[0];
    bool is_character_sign = (first_character == '-' || first_character == '+');
    if ((is_character_sign || first_character == '.') && length == 1) {
        return false;
    }
    if (length == 2 && is_character_sign && value[1] == '.') {
        return false;
    }
    return (is_character_sign || first_character == '.') ||
           (first_character >= '0' && first_character <= '9');
}

int calculate(Token *tok) {
    Stack numbers_stack;
    Stack operators_stack;

    initialize_stack(&numbers_stack);
    initialize_stack(&operators_stack);

    while (1) {
        char *token = tok->value;

        if (is_number(token)) {
            push(&numbers_stack, atoi(token));
        }
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0) {
            push(&operators_stack, token[0]);
        }
    }

    int popped_number = pop(&numbers_stack);
    int popped_operator = pop(&operators_stack);

    printf("popped number %d\n", popped_number);
    printf("popped operator %c\n", popped_operator);

    return 1;
}