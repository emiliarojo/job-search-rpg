#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character.h"
#include "scenario.h"
#include "json_loader.h"
#include "battle.h"
#include "graph.h"

// Function to save the game state to a file
void save_game(Character *player, GraphNode *current_node) {
    FILE *file = fopen("savegame.txt", "w");
    if (!file) {
        perror("Failed to save game");
        return;
    }
    // Save player state and current scenario
    fprintf(file, "%s %d %d %d\n", player->name, player->hp, player->atk, player->def);
    fprintf(file, "%s\n", current_node->scenario.name);
    fclose(file);
}

// Function to load the game state from a file
void load_game(Character *player, GraphNode **current_node, ScenarioGraph *graph) {
    FILE *file = fopen("savegame.txt", "r");
    if (!file) {
        perror("Failed to load game");
        return;
    }
    // Load player state and current scenario
    char name[50];
    fscanf(file, "%s %d %d %d", player->name, &player->hp, &player->atk, &player->def);
    fscanf(file, "%s", name);

    // Find the scenario node corresponding to the saved state
    GraphNode *node = graph->head;
    while (node != NULL) {
        if (strcmp(node->scenario.name, name) == 0) {
            *current_node = node;
            break;
        }
        node = node->next[0]; // linear traversal
    }
    fclose(file);
}

// Function to display the game introduction
void display_intro() {
    printf("Welcome to Job Search RPG!\n\n");
    printf("In this game, you will navigate through various job search scenarios, make decisions, and battle recruiters and interviewers.\n");
    printf("Make strategic use of your skills to defeat enemies and progress through the game.\n");
    printf("Good luck!\n\n");
}

// Function to display available skills for the player to choose
void display_skills() {
    printf("Choose 4 skills for your character:\n");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (strlen(skills[i].name) > 0) {
            printf("%d. %s - %s\n", i + 1, skills[i].name, skills[i].description);
        }
    }
}

// Function to display the current scenario and decisions
void display_scenario(GraphNode *current_node) {
    printf("\n===================================================\n");
    printf("%s: %s\n", current_node->scenario.name, current_node->scenario.description);
    for (int i = 0; i < current_node->scenario.num_decisions; i++) {
        printf("%d. %s\n", i + 1, current_node->scenario.decisions[i].text);
    }
    printf("\n===================================================\n");
}

// Main function to run the game
int main() {
    display_intro();

    ScenarioGraph graph;
    initialize_graph(&graph);
    Scenarios scenarios;
    load_scenarios(&scenarios, "data/scenarios.json");

    Character player;
    load_skills("data/skills.json");
    create_character(&player);

    load_scenarios_into_graph(&graph, "data/scenarios.json");

    int choice;
    printf("1. New Game\n2. Load Game\n");
    scanf("%d", &choice);

    GraphNode *current_node = NULL;
    if (choice == 2) {
        load_game(&player, &current_node, &graph);
        if (current_node == NULL) {
            printf("Failed to load game, starting new game...\n");
            current_node = graph.head;
        }
    } else {
        current_node = graph.head;
    }

    while (current_node != NULL) {
        display_scenario(current_node);

        int decision;
        while (1) {
            scanf("%d", &decision);
            if (decision < 1 || decision > current_node->scenario.num_decisions) {
                printf("Invalid choice. Please choose a valid decision.\n");
            } else {
                break;
            }
        }

        printf("\n%s\n", current_node->scenario.decisions[decision - 1].pre_battle_text);
        for (int i = 0; i < current_node->scenario.decisions[decision - 1].num_enemies; i++) {
            Enemy enemy = current_node->scenario.decisions[decision - 1].enemies[i];
            initiate_battle(&player, &enemy);
        }
        printf("\n%s\n", current_node->scenario.decisions[decision - 1].post_battle_text);

        current_node = get_next_scenario(current_node, decision - 1);
        save_game(&player, current_node);
    }

    printf("Thank you for playing!\n");
    return 0;
}
