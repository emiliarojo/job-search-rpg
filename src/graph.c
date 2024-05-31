#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "json_loader.h"

// Function to initialize the scenario graph
void initialize_graph(ScenarioGraph* graph) {
    graph->head = NULL;
    graph->size = 0;
}

// Function to create a graph node for a given scenario
GraphNode* create_graph_node(Scenario* scenario) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->scenario = *scenario;
    node->next[0] = NULL;
    node->next[1] = NULL;
    return node;
}

// Function to add edges between graph nodes
void add_graph_edge(GraphNode* from, GraphNode* to1, GraphNode* to2) {
    if (to1 != NULL) {
        from->next[0] = to1;
    }
    if (to2 != NULL) {
        from->next[1] = to2;
    }
}

// Function to load scenarios from a file and build the graph
void load_scenarios_into_graph(ScenarioGraph* graph, const char* filename) {
    Scenario scenarios[4]; // Array to hold the loaded scenarios
    int scenario_count = 4; // Number of scenarios
    load_scenarios((Scenarios*)&scenarios, filename); // Load scenarios from the JSON file

    GraphNode* nodes[4]; // Array to hold the graph nodes
    for (int i = 0; i < scenario_count; i++) {
        nodes[i] = create_graph_node(&scenarios[i]);
    }

    // Manually add edges between the graph nodes
    add_graph_edge(nodes[0], nodes[1], nodes[2]);
    add_graph_edge(nodes[1], nodes[3], NULL);
    add_graph_edge(nodes[2], nodes[3], NULL);
    add_graph_edge(nodes[3], NULL, NULL);

    // Set the head of the graph and update the size
    graph->head = nodes[0];
    graph->size = scenario_count;
}

// Function to get the next scenario based on the decision index
GraphNode* get_next_scenario(GraphNode* current, int decision_index) {
    return current->next[decision_index];
}
