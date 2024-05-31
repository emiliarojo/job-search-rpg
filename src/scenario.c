#include <stdio.h>
#include <string.h>
#include "scenario.h"
#include "json_loader.h"
#include "battle.h"

extern Enemy enemies[MAX_ENEMIES];

// Function to navigate through a scenario
int navigate_scenario(Scenarios *scenarios, Character *player, int current_scenario) {
    Scenario *scenario = &scenarios->scenario_list[current_scenario];

    // Display the current scenario's name and description
    printf("%s: %s\n", scenario->name, scenario->description);

    // Display the available decisions
    for (int i = 0; i < scenario->num_decisions; i++) {
        printf("%d. %s\n", i + 1, scenario->decisions[i].text);
    }

    // Get the player's choice
    int choice;
    scanf("%d", &choice);
    choice -= 1;

    // Validate the player's choice
    if (choice < 0 || choice >= scenario->num_decisions) {
        printf("Invalid choice.\n");
        return current_scenario;
    }

    Decision *decision = &scenario->decisions[choice];
    printf("%s\n", decision->pre_battle_text);

    // If there are enemies in the decision, initiate a battle
    if (decision->num_enemies > 0) {
        for (int i = 0; i < decision->num_enemies; i++) {
            Enemy *battle_enemy = &decision->enemies[i];
            initiate_battle(player, battle_enemy);
        }
        printf("%s\n", decision->post_battle_text);
    }

    // Return the next scenario index
    return decision->next_scenario;
}
