#include <stdio.h>
#include <stdlib.h>
#include "character.h"
#include "scenario.h"
#include "json_loader.h"
#include "battle.h"
#include "graph.h"

int main() {
    printf("Welcome to Job Search RPG!\n");

    ScenarioGraph graph;
    initialize_graph(&graph);
    Scenarios scenarios;
    load_scenarios(&scenarios, "data/scenarios.json");

    Character player;
    load_skills("data/skills.json");
    create_character(&player);

    load_scenarios_into_graph(&graph, "data/scenarios.json");

    GraphNode* current_node = graph.head;
    while (current_node != NULL) {
        printf("%s: %s\n", current_node->scenario.name, current_node->scenario.description);
        for (int i = 0; i < current_node->scenario.num_decisions; i++) {
            printf("%d. %s\n", i + 1, current_node->scenario.decisions[i].text);
        }

        int decision;
        while (1) {
            scanf("%d", &decision);
            if (decision < 1 || decision > current_node->scenario.num_decisions) {
                printf("Invalid choice. Please choose a valid decision.\n");
            } else {
                break;
            }
        }

        printf("%s\n", current_node->scenario.decisions[decision - 1].pre_battle_text);
        for (int i = 0; i < current_node->scenario.decisions[decision - 1].num_enemies; i++) {
            Enemy enemy = current_node->scenario.decisions[decision - 1].enemies[i];
            initiate_battle(&player, &enemy);
        }
        printf("%s\n", current_node->scenario.decisions[decision - 1].post_battle_text);

        current_node = get_next_scenario(current_node, decision - 1);
    }

    printf("Thank you for playing!\n");
    return 0;
}
