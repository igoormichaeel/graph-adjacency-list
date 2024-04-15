#pragma once
#include <stdlib.h>

typedef int data_type;

typedef struct NodeObject {
    data_type data;
    struct NodeObject* prev;
    struct NodeObject* next;
} NodeObject;

typedef NodeObject* List;

List* newList(void);
void freeList(List* list);
void insertEndList(List* list, int vertex);
void insertListOrd(List* list, int vertex);
void removeFromList(List* list, int vertex);
void showList(List* list);
