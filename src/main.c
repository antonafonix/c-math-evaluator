#include "calculation.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s \"expression\"\n", argv[0]);
        return 1;
    }

    char *source = argv[1];

    Tokenizer t;
    tokenizer_init(&t, source);

    int capacity = 8;
    int count = 0;
    Token *tokens = (Token *)malloc(capacity * sizeof(Token));

    if (tokens == NULL)
        return 1;

    while (1) {
        Token tok = tokenizer_next_token(&t);

        if (tok.type == TOKEN_EOF) {
            break;
        }

        if (count >= capacity) {
            capacity *= 2;
            Token *temp = (Token *)realloc(tokens, capacity * sizeof(Token));
            if (!temp) {
                free(tokens);
                return 1;
            }
            tokens = temp;
        }

        tokens[count++] = tok;

        if (tok.type == TOKEN_EOF)
            break;
    }
    int calc;
    for (int i = 0; i < count; i++) {
        printf("Token %d -> Type: %d, Value: %s\n", i, tokens[i].type, tokens[i].value);

        calc = calculate(&tokens[i]);
    }

    printf("calc %d\n", calc);

    free(tokens);

    return 0;
}
