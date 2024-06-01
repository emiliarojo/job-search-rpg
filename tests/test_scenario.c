#include <stdio.h>
#include <assert.h>
#include "../src/scenario.h"
#include "../src/character.h"
#include "../src/json_loader.h"

void test_scenario_navigation() {
    Scenarios scenarios;
    Character player;

    // Load scenarios and skills
    load_scenarios(&scenarios, "data/scenarios.json");
    load_skills("data/skills.json");
    create_character(&player);

    // Start at the first scenario
    int current_scenario = 0;

    // Navigate through scenarios and check transitions
    current_scenario = navigate_scenario(&scenarios, &player, current_scenario);
    assert(current_scenario != 0);
    printf("test_scenario_navigation passed.\n");
}

int main() {
    test_scenario_navigation();
    printf("All scenario tests passed.\n");
    return 0;
}
