#pragma once
#include <stdbool.h>
#include <stdlib.h>

typedef int data_type;

typedef struct _stack_node {
    data_type data;
    struct _stack_node* prev;
    struct _stack_node* next;
} S_NodeObject;

typedef struct _stack {
    struct _stack_node* first;
    struct _stack_node* last;
    size_t size;
} Stack;

S_NodeObject* newS_Node(data_type val);

Stack* newStack(void);
void freeStack(Stack** stack);

size_t getStackSize(Stack* stack);
bool isStackEmpty(Stack* stack);

void push(Stack* stack, int vertex);
void pop(Stack* stack);
data_type top(Stack* stack);
void showStack(Stack* stack);