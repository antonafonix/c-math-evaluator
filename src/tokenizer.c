#include "tokenizer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char current = t->source[t->position];

    if (current == '\0') {
        tok.type = TOKEN_EOF;
        return tok;
    }

    if (current >= '0' && current <= '9') {
        tok.type = TOKEN_NUMBER;

        int val_index = 0;

        while (t->source[t->position] >= '0' && t->source[t->position] <= '9') {
            if (val_index < 31) {
                tok.value[val_index++] = t->source[t->position];
            }
            t->position++;
        }

        tok.value[val_index] = '\0';
        return tok;
    }

    if (current == '+' || current == '-' || current == '*' || current == '/') {
        tok.type = TOKEN_OPERATOR;
        tok.value[0] = current;
        tok.value[1] = '\0';
        t->position++;
        return tok;
    }

    if (current == ')') {
        tok.type = TOKEN_RPAREN;
        tok.value[0] = current;
        tok.value[1] = '\0';
        t->position++;
        return tok;
    } else if (current == '(') {
        tok.type = TOKEN_LPAREN;
        tok.value[0] = current;
        tok.value[1] = '\0';
        t->position++;
        return tok;
    }

    t->position++;
    tok.type = TOKEN_EOF;
    return tok;
}
