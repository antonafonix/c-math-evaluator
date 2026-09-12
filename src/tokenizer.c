#include "tokenizer.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_number(const char *string) {
    if (string == NULL || string[0] == '\0')
        return false;

    int dot_counter = 0;
    size_t length = 1;

    for (char character = string[1]; character != '\0'; ++length, character = string[length]) {
        const bool is_valid_character =
            (character >= '0' && character <= '9') || (character == '.' && ++dot_counter == 1);

        if (is_valid_character == false)
            return false;
    }

    const char first_character = string[0];
    bool is_character_sign = (first_character == '-' || first_character == '+');
    if ((is_character_sign || first_character == '.') && length == 1) {
        return false;
    }
    if (length == 2 && is_character_sign && string[1] == '.') {
        return false;
    }
    return (is_character_sign || first_character == '.') ||
           (first_character >= '0' && first_character <= '9');
}

void tokenizer_init(Tokenizer *t, const char *source) {
    t->source = source;
    t->position = 0;
}

Token tokenizer_next_token(Tokenizer *t) {
    Token tok;
    memset(&tok, 0, sizeof(Token));

    while (t->source[t->position] == ' ' || t->source[t->position] == '\t') {
        t->position++;
    }

    char current[strlen(t->source)];

    memcpy(current, t->source, strlen(t->source));

    if (current[0] == '\0') {
        tok.type = TOKEN_EOF;
        return tok;
    }

    if (is_number(current)) {
        tok.type = TOKEN_NUMBER;

        int val_index = 0;

        while (t->source[t->position] >= '0' && t->source[t->position] <= '9') {
            if (val_index < 31) {
                tok.value[val_index++] = t->source[t->position];
            }
            t->position++;
        }

        tok.value[val_index] = '\0';
        printf("tok %s\n", tok.value);
        return tok;
    }

    if (current[0] == '+' || current[0] == '-' || current[0] == '*' || current[0] == '/') {
        tok.type = TOKEN_OPERATOR;
        tok.value[0] = current[0];
        tok.value[1] = '\0';
        t->position++;
        return tok;
    }

    if (current[0] == ')') {
        tok.type = TOKEN_RPAREN;
        tok.value[0] = current[0];
        tok.value[1] = '\0';
        t->position++;
        return tok;
    } else if (current[0] == '(') {
        tok.type = TOKEN_LPAREN;
        tok.value[0] = current[0];
        tok.value[1] = '\0';
        t->position++;
        return tok;
    }

    t->position++;
    tok.type = TOKEN_EOF;
    return tok;
}
