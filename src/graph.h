#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 4

typedef struct {
    int adj_matrix[MAX_NODES][MAX_NODES];
    int num_nodes;
} Graph;

void init_graph(Graph *graph, int num_nodes);
void add_edge(Graph *graph, int src, int dest);
int *get_neighbors(Graph *graph, int node, int *num_neighbors);

#endif
