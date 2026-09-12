#ifndef CALCULATION_H
#define CALCULATION_H

#include "tokenizer.h"
#include "queue.h"
#include "stack.h"

int get_priority(char op);

bool is_number(const char* string);

void to_postfix(Token *tok, int size, Queue* output_queue, Stack* operators_stack);

int calculate_postfix(Token *tokens, int size);

#endif