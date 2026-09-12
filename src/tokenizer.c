#include "tokenizer.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenizer_init(Tokenizer *t, const char *source) {
    t->source = source;
    t->position = 0;
}

Token tokenizer_next_token(Tokenizer *t) {
    while (t->source[t->position] == ' ' || t->source[t->position] == '\t') {
        t->position++;
    }

    Token tok;

    char current = t->source[t->position];

    if (current == '\0') {
        tok.type = TOKEN_EOF;
        return tok;
    }

    if (isdigit(current) || current == '.') {
        tok.type = TOKEN_NUMBER;

        char *next_ptr;
        tok.value.number_value = strtod(&t->source[t->position], &next_ptr);

        t->position = next_ptr - t->source;
        printf("tok number %f\n", tok.value.number_value);
        return tok;
    }

    switch (current) {
    case '+':
    case '-':
    case '*':
    case '/':
        tok.value.operator_char = current;
        tok.type = TOKEN_OPERATOR;
        t->position++;
        return tok;
    case '(':
        tok.type = TOKEN_LPAREN;
        t->position++;

        return tok;
    case ')':
        tok.type = TOKEN_RPAREN;
        t->position++;

        return tok;
    }

    t->position++;
    tok.type = TOKEN_EOF;
    return tok;
}
