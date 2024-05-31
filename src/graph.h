#ifndef GRAPH_H
#define GRAPH_H

#include "scenario.h"

typedef struct GraphNode {
    Scenario scenario;
    struct GraphNode* next[2];
} GraphNode;

typedef struct {
    GraphNode* head;
    int size;
} ScenarioGraph;

void initialize_graph(ScenarioGraph* graph);
GraphNode* create_graph_node(Scenario* scenario);
void add_graph_edge(GraphNode* from, GraphNode* to1, GraphNode* to2);
void load_scenarios_into_graph(ScenarioGraph* graph, const char* filename);
GraphNode* get_next_scenario(GraphNode* current, int decision_index);

#endif
