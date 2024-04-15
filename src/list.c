#include "list.h"

#include <stdio.h>
#include <stdlib.h>

/**

*/
List* newList(void) {
    List* list = malloc(sizeof *list);
    if (list != NULL) *list = NULL;
    return list;
}

/**

*/
void freeList(List* list) {
    if (list != NULL) {
        NodeObject* auxiliarNode;
        while (*list != NULL) {
            auxiliarNode = *list;
            (*list) = (*list)->next;
            free(auxiliarNode);
        }
        free(list);
    }
}

/**

*/
void insertEndList(List* list, int vertex) {
    if (list == NULL) return;

    NodeObject* node = malloc(sizeof *node);
    if (node == NULL) return;

    node->data = vertex;
    node->next = NULL;

    // Empty list: insert at the start
    if (*list == NULL) {
        node->prev = NULL;
        *list = node;
    } else {
        NodeObject* auxiliarNode = *list;
        while (auxiliarNode->next != NULL && auxiliarNode->data != vertex)
            auxiliarNode = auxiliarNode->next;

        // If node already exists
        if (auxiliarNode->data == vertex) {
            free(node);
            return;
        }

        auxiliarNode->next = node;
        node->prev = auxiliarNode;
    }
}

/**

*/
void insertListOrd(List* list, int vertex) {  //, char pessoas[10][50]){
    if (list == NULL) return;

    NodeObject* node = malloc(sizeof *node);
    if (node == NULL) return;

    node->data = vertex;

    // Empty list: insert at the start
    if (*list == NULL) {
        node->next = NULL;
        node->prev = NULL;
        *list = node;
    } else {
        NodeObject *ant, *atual = *list;
        // while (atual != NULL && strcmp(pessoas[vertex], pessoas[atual->data])
        // > 0)
        while (atual != NULL && vertex > atual->data) {
            ant = atual;
            atual = atual->next;
        }

        if (atual == *list) {
            node->prev = NULL;
            node->next = atual;
            atual->prev = node;
            *list = node;
        } else {
            node->next = ant->next;
            node->prev = ant;
            ant->next = node;
            if (atual != NULL) atual->prev = node;
        }
    }
}

/**

*/
void removeFromList(List* list, int vertex) {
    if (list == NULL) return;
    if (*list == NULL) return;  // Empty list

    NodeObject* node = *list;
    while (node != NULL && node->data != vertex) node = node->next;

    // Node not found
    if (node == NULL) return;

    // Remove first node
    if (node->prev == NULL)
        *list = node->next;
    else
        (node->prev)->next = node->next;

    if (node->next != NULL) (node->next)->prev = node->prev;

    free(node);
}

/**

*/
void showList(List* list) {
    if (list == NULL) return;
    NodeObject* node = *list;

    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("\n");
}