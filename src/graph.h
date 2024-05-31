#ifndef GRAPH_H
#define GRAPH_H

#include "scenario.h"

// Definition of a graph node, representing a scenario
typedef struct GraphNode {
    Scenario scenario;
    struct GraphNode* next[2];
} GraphNode;

// Definition of the scenario graph
typedef struct {
    GraphNode* head;
    int size;
} ScenarioGraph;

// Function to initialize the scenario graph
void initialize_graph(ScenarioGraph* graph);

// Function to create a graph node for a given scenario
GraphNode* create_graph_node(Scenario* scenario);

// Function to add edges between graph nodes
void add_graph_edge(GraphNode* from, GraphNode* to1, GraphNode* to2);

// Function to load scenarios from a file and build the graph
void load_scenarios_into_graph(ScenarioGraph* graph, const char* filename);

// Function to get the next scenario based on the decision index
GraphNode* get_next_scenario(GraphNode* current, int decision_index);

#endif
