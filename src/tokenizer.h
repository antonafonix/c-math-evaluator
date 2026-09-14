#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdbool.h>

typedef enum { TOKEN_NUMBER, TOKEN_OPERATOR, TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_EOF } TokenType;

typedef struct {
    TokenType type;
    union {
        double number_value;
        char operator_char;
    } value;
} Token;

typedef struct {
    const char *source;
    int position;
} Tokenizer;

void tokenizer_init(Tokenizer *t, const char *source);

Token tokenizer_next_token(Tokenizer *t);

#endif