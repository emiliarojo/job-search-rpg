#include <stdlib.h>
#include "graph.h"

void init_graph(Graph *graph, int num_nodes) {
    graph->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph *graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
}

int *get_neighbors(Graph *graph, int node, int *num_neighbors) {
    int *neighbors = (int *)malloc(graph->num_nodes * sizeof(int));
    *num_neighbors = 0;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->adj_matrix[node][i] == 1) {
            neighbors[(*num_neighbors)++] = i;
        }
    }
    return neighbors;
}
