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

    const char *source = argv[1];

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
    }

    int calc = calculate_postfix(tokens, count);

    printf("calc %d\n", calc);

    free(tokens);

    return 0;
}
