#include <stdio.h>
#include "scenario.h"
#include "battle.h"

int navigate_scenario(Scenarios *scenarios, Character *player, int current_scenario) {
    Scenario *scenario = &scenarios->scenario_list[current_scenario];
    printf("%s\n", scenario->description);

    for (int i = 0; i < scenario->num_decisions; i++) {
        printf("%d. %s\n", i + 1, scenario->decisions[i].text);
    }

    int choice;
    scanf("%d", &choice);
    choice -= 1;

    Decision *decision = &scenario->decisions[choice];
    printf("%s\n", decision->pre_battle_text);

    for (int i = 0; i < decision->num_enemies; i++) {
        initiate_battle(player, &decision->enemies[i]);
    }

    printf("%s\n", decision->post_battle_text);

    return decision->next_scenario;
}
