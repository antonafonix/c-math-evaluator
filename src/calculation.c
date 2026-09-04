#include "calculation.h"
#include "stack.h"
#include "tokenizer.h"

#include <stdio.h>
#include <stdlib.h>
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

int calculate(Token *tokens, int size) {
    Stack numbers_stack;
    Stack operators_stack;

    initialize_stack(&numbers_stack);
    initialize_stack(&operators_stack);

    int index = 0;
    while (index < size) {

        switch (tokens[index].type) {
        case TOKEN_NUMBER:
            push(&numbers_stack, atoi(tokens[index].value));
            printf("TOKEN NUMBER IS ADDED\n");
            break;
        case TOKEN_OPERATOR:
            push(&operators_stack, tokens[index].value[0]);
            printf("TOKEN OPERATOR IS ADDED\n");
            break;
        default:
            break;
        }

        index++;
    }

    return 1;
}