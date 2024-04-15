#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"

void fillGraphRandomly(Graph* graph, int numNodes, int numEdges) {
    srand(time(NULL));  // Seed para gerar números aleatórios

    for (int i = 0; i < numEdges; ++i) {
        int source = rand() % numNodes;
        int destination = rand() % numNodes;

        insertEdge(graph, source, destination);
    }
}

int main() {
    int numNodes = 5000;
    // Definindo a densidade das arestas (exemplo: 5%)
    double density = 0.05;
    // Definindo os tamanhos dos problemas para as cinco execuções
    int problemSizes[5] = {numNodes / 4, numNodes / 2, numNodes, numNodes * 2,
                           numNodes * 4};
    int numProblems = sizeof(problemSizes) / sizeof(problemSizes[0]);

    for (int i = 0; i < numProblems; ++i) {
        clock_t start = clock();
        printf("\n--- Execution %d ---\n", i + 1);
        printf("Number of nodes: %d\n", problemSizes[i]);

        // Calculando o número de arestas com base na densidade
        int numEdges = problemSizes[i] * (problemSizes[i] - 1) / 2 * density;

        printf("Number of edges: %d\n", numEdges);

        Graph* graph = newGraph(problemSizes[i]);

        fillGraphRandomly(graph, problemSizes[i], numEdges);

        // showAdjList(graph);

        bool isConnected = isConnectedUsingBFS(graph, 0, true);

        if (isConnected)
            printf("The graph is connected.\n");
        else
            printf("The graph is not connected.\n");

        freeGraph(graph);
        clock_t end = clock();
        double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Execution time: %.6f seconds\n", elapsedTime);
    }

    return 0;
}
