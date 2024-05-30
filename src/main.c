#include <stdio.h>
#include <stdlib.h>
#include "character.h"
#include "battle.h"
#include "scenario.h"
#include "json_loader.h"

int main() {
    Character player;
    Scenarios scenarios;
    load_scenarios(&scenarios, "data/scenarios.json");
    load_skills("data/skills.json");

    printf("Welcome to Job Search RPG!\n");
    create_character(&player);

    int current_scenario = 0;
    while (current_scenario != -1) {
        current_scenario = navigate_scenario(&scenarios, &player, current_scenario);
    }

    printf("Thank you for playing Job Search RPG!\n");
    return 0;
}
