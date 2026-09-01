#include "tokenizer.h"

void tokenizer_init(Tokenizer *t, const char *source) {
    t->source = source;
    t->position = 0;
}
