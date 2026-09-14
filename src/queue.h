#ifndef QUEUE_H
#define QUEUE_H

#include "tokenizer.h"
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    Token items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize_queue(Queue *queue);

bool is_queue_empty(Queue *queue);

bool is_queue_full(Queue *queue);

void enqueue(Queue *q, Token token);

void dequeue(Queue *q);

void printQueue(Queue *q);

Token peek_queue(Queue *q);

#endif