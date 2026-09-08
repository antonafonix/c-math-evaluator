#ifndef CALCULATION_H
#define CALCULATION_H

#include "tokenizer.h"

int get_priority(char op);

int calculate(Token *tok, int size);

#endif