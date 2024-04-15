#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

QNodeObject* newQNode(data_type val) {
    QNodeObject* node = malloc(sizeof *node);
    node->next = NULL;
    node->data = val;

    return node;
}

Queue* newQueue(void) {
    Queue* queue = malloc(sizeof *queue);
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;

    return queue;
}

void freeQueue(Queue** _queue) {
    Queue* queue = *_queue;

    QNodeObject* node = queue->first;
    while (node != NULL) {
        QNodeObject* auxiliar = node;
        node = node->next;
        free(auxiliar);
    }

    free(queue);
    *_queue = NULL;
}

size_t getSize(Queue* queue) { return queue->size; }

bool isEmpty(Queue* queue) {
    if (getSize(queue) == 0) return true;
    return false;
}

void enqueue(Queue* queue, int vertex) {
    QNodeObject* node = newQNode(vertex);
    if (isEmpty(queue)) {
        queue->first = node;
        queue->last = node;
    } else {
        queue->last->next = node;
        queue->last = node;
    }
    queue->size++;
}

void dequeue(Queue* queue) {
    if (!isEmpty(queue)) {
        QNodeObject* node = queue->first;
        if (queue->size == 1) {
            queue->first = NULL;
            queue->last = NULL;
        } else {
            queue->first = queue->first->next;
        }

        free(node);
        queue->size--;
    }
}

data_type peek(Queue* queue) { return queue->first->data; }