#include "graph.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "queue.h"
#include "stack.h"

/*
static int cmp_str_vizinhos(const void *lhs, const void *rhs){
    return *(int*)rhs - *(int*)lhs;
}
*/

/**
    Aloca espaço para o grafo e para a lista de adjacencia (inicialmente vazia)
   e inicializa a quantidade de vertices e arestas
    @param int numberOfVertices: Numero de vertices do grafo
    @return Graph* graph: Ponteiro para o objeto grafo
*/
Graph* newGraph(int _numberOfVertices) {
    Graph* graph = malloc(sizeof *graph);
    graph->numberOfVertices = _numberOfVertices;
    graph->numberOfEdges = 0;
    graph->adjList = malloc(_numberOfVertices * sizeof(List));
    for (int i = 0; i < _numberOfVertices; i++) graph->adjList[i] = newList();
    return graph;
}

/**
    Libera espaço de memoria alocado previamente para o objeto
    @param Graph* graph: Ponteiro para o objeto grafo
*/
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numberOfVertices; i++)
        freeList(graph->adjList[i]);
    free(graph->adjList);
    free(graph);
}

/**
    Insere o nodo com o valor do vertice de destino na lista de adjacencia do
   vertice de origem.
    @param Graph* graph: Ponteiro para o grafo que deseja inserir a aresta
    @param int vOrig: Valor numerico do vertice de saida da aresta
    @param int vDest: Valor numerico do vertice de chegada da aresta
*/
void insertEdge(Graph* graph, int vOrig, int vDest) {
    insertListOrd(graph->adjList[vOrig], vDest);
}

/**
    Remove o nodo com o valor do vertice de destino na lista de adjacencia do
   vertice de origem.
    @param Graph* graph: Ponteiro para o grafo que deseja inserir a aresta
    @param int vOrig: Valor numerico do vertice de saida da aresta
    @param int vDest: Valor numerico do vertice de chegada da aresta
*/
void removeEdge(Graph* graph, int vOrig, int vDest) {
    removeFromList(graph->adjList[vOrig], vDest);
}

/**
    Exibe a lista de adjacencia do grafo com os valores numericos
    @param Graph* graph: Ponteiro para o grafo que deseja exibir a lista de
   adjacencia
*/
void showAdjList(Graph* graph) {
    for (int i = 0; i < graph->numberOfVertices; i++) {
        printf("%d: ", i);
        showList(graph->adjList[i]);
    }
    printf("\n");
}

/**
    Transpoe um grafo (inverte as arestas direcionadas) e retorna o grafo
   transposto
    @param Graph* graph: Ponteiro para o grafo que deseja calcular o grafo
   transposto
    @return Graph* newGraph: Ponteiro para o grafo transposto calculado a partir
   da entrada
*/
Graph* transpose(Graph* graph) {
    Graph* graphT = newGraph(graph->numberOfVertices);
    NodeObject* node;
    for (int i = 0; i < graph->numberOfVertices; i++) {
        // strcpy(newG->pessoas[i], g->pessoas[i]);
        node = *(graph->adjList[i]);
        while (node != NULL) {
            insertEdge(graphT, node->data, i);
            node = node->next;
        }
    }
    return graphT;
}

void BFS(Graph* graph, int startVertex, colorType* color, int* distance,
         int* antecessor, bool verbose) {
    color[startVertex] = grey;
    distance[startVertex] = 0;
    antecessor[startVertex] = -1;

    Queue* queue = newQueue();
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int processingVertex = peek(queue);
        // if (verbose) printf("%d -> ", processingVertex);
        dequeue(queue);
        NodeObject* node = *(graph->adjList[processingVertex]);

        while (node != NULL) {
            if (color[node->data] == white) {
                color[node->data] = grey;
                distance[node->data] = distance[processingVertex] + 1;
                antecessor[node->data] = processingVertex;
                enqueue(queue, node->data);
            }
            node = node->next;
        }
        color[processingVertex] = black;
    }

    freeQueue(&queue);
}

void DFS(Graph* graph, int startVertex, colorType* color, int* distance,
         int* antecessor) {
    color[startVertex] = grey;
    distance[startVertex] = 0;
    antecessor[startVertex] = -1;

    Stack* stack = newStack();
    push(stack, startVertex);

    while (!isStackEmpty(stack)) {
        int processVertex = top(stack);
        pop(stack);
        NodeObject* node = *(graph->adjList[processVertex]);

        while (node != NULL) {
            if (color[processVertex] == white) {
                color[node->data] = grey;
                distance[node->data] = distance[processVertex] + 1;
                antecessor[node->data] = processVertex;
                push(stack, node->data);
            }
            node = node->next;
        }
        color[processVertex] = black;
    }

    freeStack(&stack);
}

bool isConnectedUsingBFS(Graph* graph, int startVertex, bool verbose) {
    int numberOfVertices = graph->numberOfVertices;
    int distance[numberOfVertices], antecessor[numberOfVertices];
    colorType color[numberOfVertices];

    for (int vertex = 0; vertex < numberOfVertices; vertex++) {
        color[vertex] = white;
        distance[vertex] = -1;
        antecessor[vertex] = -1;
    }

    BFS(graph, startVertex, color, distance, antecessor, verbose);
    bool isConnected = false;

    for (int i = 0; i < numberOfVertices; i++) {
        if (distance[i] == -1) isConnected = true;
    }

    return isConnected;
}