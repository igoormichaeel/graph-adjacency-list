#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"

int main(int argc, char* argv[]) {
    int numNodes = strtol(argv[1], NULL, 10);
    // Definindo a densidade das arestas (exemplo: 5%)
    double density = 0.05;

    printf("Number of nodes: %d\n", numNodes);

    // Calculando o número de arestas com base na densidade
    int numEdges = numNodes * (numNodes - 1) / 2 * density;

    printf("Number of edges: %d\n", numEdges);

    Graph* graph = newGraph(numNodes);

    fillGraphRandomly(graph, numNodes, numEdges);

    // showAdjList(graph);

    bool isConnected = isConnectedUsingBFS(graph, 0, true);

    if (isConnected)
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    freeGraph(graph);

    return 0;
}
