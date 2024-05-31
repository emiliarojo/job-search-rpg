#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "json_loader.h"

void initialize_graph(ScenarioGraph* graph) {
    graph->head = NULL;
    graph->size = 0;
}

GraphNode* create_graph_node(Scenario* scenario) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->scenario = *scenario;
    node->next[0] = NULL;
    node->next[1] = NULL;
    return node;
}

void add_graph_edge(GraphNode* from, GraphNode* to1, GraphNode* to2) {
    if (to1 != NULL) {
        from->next[0] = to1;
    }
    if (to2 != NULL) {
        from->next[1] = to2;
    }
}

void load_scenarios_into_graph(ScenarioGraph* graph, const char* filename) {
    Scenario scenarios[4];
    int scenario_count = 4;
    load_scenarios((Scenarios*)&scenarios, filename);

    GraphNode* nodes[4];
    for (int i = 0; i < scenario_count; i++) {
        nodes[i] = create_graph_node(&scenarios[i]);
    }

    add_graph_edge(nodes[0], nodes[1], nodes[2]);
    add_graph_edge(nodes[1], nodes[3], NULL);
    add_graph_edge(nodes[2], nodes[3], NULL);
    add_graph_edge(nodes[3], NULL, NULL);

    graph->head = nodes[0];
    graph->size = scenario_count;
}

GraphNode* get_next_scenario(GraphNode* current, int decision_index) {
    return current->next[decision_index];
}
