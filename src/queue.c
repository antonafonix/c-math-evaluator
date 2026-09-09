#include "queue.h"
#include <stdbool.h>
#include <stdio.h>

void initialize_queue(Queue *q) {
    q->front = -1;
    q->rear = 0;
}

bool is_queue_empty(Queue *q) { return (q->front == q->rear - 1); }

bool is_queue_full(Queue *q) { return (q->rear == MAX_SIZE); }

void enqueue(Queue *q, int value) {
    if (is_queue_full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear++;
}

void dequeue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->front++;
}

int peek_queue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front + 1];
}

void printQueue(Queue *q) {
    if (is_queue_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front + 1; i < q->rear; i++) {
        printf("%c ", q->items[i]);
    }
    printf("\n");
}
