#include <stdio.h>
#include <string.h>
#include "scenario.h"
#include "json_loader.h"
#include "battle.h"  // Include battle.h to use initiate_battle

extern Enemy enemies[MAX_ENEMIES];

int navigate_scenario(Scenarios *scenarios, Character *player, int current_scenario) {
    Scenario *scenario = &scenarios->scenario_list[current_scenario];
    printf("%s: %s\n", scenario->name, scenario->description);

    for (int i = 0; i < scenario->num_decisions; i++) {
        printf("%d. %s\n", i + 1, scenario->decisions[i].text);
    }

    int choice;
    scanf("%d", &choice);
    choice -= 1;

    if (choice < 0 || choice >= scenario->num_decisions) {
        printf("Invalid choice.\n");
        return current_scenario;
    }

    Decision *decision = &scenario->decisions[choice];
    printf("%s\n", decision->pre_battle_text);

    // Assume only one enemy for simplicity
    if (decision->num_enemies > 0) {
        Enemy *battle_enemy = &decision->enemies[0];

        // Debugging to verify the enemy assignment
        printf("Battle Enemy: %s with %d skills\n", battle_enemy->name, battle_enemy->num_skills);
        for (int i = 0; i < battle_enemy->num_skills; i++) {
            printf("  Skill %d: %s - %s\n", i + 1, battle_enemy->skills[i].name, battle_enemy->skills[i].description);
        }

        initiate_battle(player, battle_enemy);
        printf("%s\n", decision->post_battle_text);
    }

    return decision->next_scenario;
}
