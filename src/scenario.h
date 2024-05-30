#ifndef SCENARIO_H
#define SCENARIO_H

#include "character.h"
#include "enemy.h"

#define MAX_DECISIONS 10

typedef struct {
    char text[200];
    char pre_battle_text[200];
    char post_battle_text[200];
    Enemy enemies[MAX_ENEMIES];
    int num_enemies;
    int next_scenario;
} Decision;

typedef struct {
    char name[50];
    char description[500];
    Decision decisions[MAX_DECISIONS];
    int num_decisions;
} Scenario;

typedef struct {
    Scenario scenario_list[4];
} Scenarios;

void load_scenarios(Scenarios *scenarios, const char *filename);
int navigate_scenario(Scenarios *scenarios, Character *player, int current_scenario);

#endif
