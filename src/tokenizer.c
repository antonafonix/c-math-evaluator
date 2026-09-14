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
    while (t->source[t->position] == ' ' ||
           t->source[t->position] == '\t') {
        t->position++;
    }

    Token tok;

    const char *current = &t->source[t->position];

    if (current[0] == '\0') {
        tok.type = TOKEN_EOF;
        return tok;
    }

    char *next_ptr;
    double number = strtod(current, &next_ptr);

    if (next_ptr != current) {
        tok.type = TOKEN_NUMBER;
        tok.value.number_value = number;

        t->position = next_ptr - t->source;

        return tok;
    }

    switch (current[0]) {
    case '+':
    case '-':
    case '*':
    case '/':
        tok.value.operator_char = current[0];
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