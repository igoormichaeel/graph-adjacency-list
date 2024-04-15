#pragma once
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

typedef List* ptrList;

typedef struct _graph {
    ptrList* adjList;  // Vetor de listas
    int numberOfVertices;
    int numberOfEdges;
} Graph;

typedef enum { white, grey, black } colorType;

Graph* newGraph(int numberOfVertices);
void freeGraph(Graph* graph);
void insertEdge(Graph* graph, int vOrig, int vDest);
void removeEdge(Graph* graph, int vOrig, int vDest);
void showAdjList(Graph* graph);
Graph* transpose(Graph* graph);

void BFS(Graph* graph, int startVertex, colorType* color, int* distance,
         int* antecessor, bool verbose);
void DFS(Graph* graph, int startVertex, colorType* color, int* distance,
         int* antecessor);
bool isConnectedUsingBFS(Graph* graph, int startVertex, bool verbose);

void fillGraphRandomly(Graph* graph, int numNodes, int numEdges);