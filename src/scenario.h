#ifndef SCENARIO_H
#define SCENARIO_H

#include "character.h"
#include "enemy.h"

#define MAX_DECISIONS 10 // Maximum number of decisions in a scenario

// Definition of the Decision structure
typedef struct {
    char text[200];
    char pre_battle_text[200];
    char post_battle_text[200];
    Enemy enemies[MAX_ENEMIES];
    int num_enemies;
    int next_scenario;
} Decision;

// Definition of the Scenario structure
typedef struct {
    char name[50];
    char description[500];
    Decision decisions[MAX_DECISIONS];
    int num_decisions;
} Scenario;

// Definition of the Scenarios structure to hold multiple scenarios
typedef struct {
    Scenario scenario_list[4];
    int scenario_count;
} Scenarios;

// Function to load scenarios from a JSON file
void load_scenarios(Scenarios *scenarios, const char *filename);

// Function to navigate through a scenario
int navigate_scenario(Scenarios *scenarios, Character *player, int current_scenario);

#endif // SCENARIO_H
