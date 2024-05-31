#include <stdio.h>
#include <stdlib.h>
#include "character.h"
#include "scenario.h"
#include "json_loader.h"
#include "battle.h"
#include "graph.h"

// Entry point of the program
int main() {
    // Welcome message
    printf("Welcome to Job Search RPG!\n");

    // Initialize the scenario graph
    ScenarioGraph graph;
    initialize_graph(&graph);

    // Load scenarios from the JSON file
    Scenarios scenarios;
    load_scenarios(&scenarios, "data/scenarios.json");

    // Initialize player character
    Character player;
    load_skills("data/skills.json");
    create_character(&player);

    // Load scenarios into the graph structure
    load_scenarios_into_graph(&graph, "data/scenarios.json");

    // Start at the head of the graph
    GraphNode* current_node = graph.head;

    // Main game loop
    while (current_node != NULL) {
        // Display the current scenario
        printf("%s: %s\n", current_node->scenario.name, current_node->scenario.description);

        // Display available decisions
        for (int i = 0; i < current_node->scenario.num_decisions; i++) {
            printf("%d. %s\n", i + 1, current_node->scenario.decisions[i].text);
        }

        int decision;
        // Loop to get a valid decision from the player
        while (1) {
            scanf("%d", &decision);
            if (decision < 1 || decision > current_node->scenario.num_decisions) {
                printf("Invalid choice. Please choose a valid decision.\n");
            } else {
                break;
            }
        }

        // Display pre-battle text
        printf("%s\n", current_node->scenario.decisions[decision - 1].pre_battle_text);

        // Initiate battles with the enemies for the chosen decision
        for (int i = 0; i < current_node->scenario.decisions[decision - 1].num_enemies; i++) {
            Enemy enemy = current_node->scenario.decisions[decision - 1].enemies[i];
            initiate_battle(&player, &enemy);
        }

        // Display post-battle text
        printf("%s\n", current_node->scenario.decisions[decision - 1].post_battle_text);

        // Move to the next scenario based on the decision
        current_node = get_next_scenario(current_node, decision - 1);
    }

    // End of game message
    printf("Thank you for playing!\n");
    return 0;
}
