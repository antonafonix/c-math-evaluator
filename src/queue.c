#include "queue.h"
#include "tokenizer.h"
#include <stdbool.h>
#include <stdio.h>

void initialize_queue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

bool is_queue_empty(Queue *q) { return q->front == q->rear; }

bool is_queue_full(Queue *q) { return (q->rear == MAX_SIZE); }

void enqueue(Queue *q, Token token) {
    if (is_queue_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->items[q->rear] = token;
    q->rear++;
}

void dequeue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}

Token peek_queue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        Token empty = {0};
        empty.type = TOKEN_EOF;
        return empty;
    }
    return q->items[q->front];
}

void printQueue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front; i < q->rear; i++) {
        if (q->items[i].type == TOKEN_NUMBER) {
            printf("%f ", q->items[i].value.number_value);
        } else if (q->items[i].type == TOKEN_OPERATOR) {
            printf("%c ", q->items[i].value.operator_char);
        }
    }
    printf("\n");
}
