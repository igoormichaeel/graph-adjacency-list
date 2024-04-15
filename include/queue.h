#pragma once
#include <stdbool.h>
#include <stdlib.h>

typedef int data_type;

typedef struct _queue_node {
    data_type data;
    struct _queue_node* next;
} QNodeObject;

typedef struct _queue {
    struct _queue_node* first;
    struct _queue_node* last;
    size_t size;
} Queue;

QNodeObject* newQNode(data_type val);

Queue* newQueue(void);
void freeQueue(Queue** queue);

size_t getSize(Queue* queue);
bool isEmpty(Queue* queue);

void enqueue(Queue* queue, int vertex);
void dequeue(Queue* queue);
data_type peek(Queue* queue);