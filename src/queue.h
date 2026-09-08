#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize_queue(Queue* queue);

bool is_empty(Queue* queue);
bool is_full(Queue* queue);

#endif