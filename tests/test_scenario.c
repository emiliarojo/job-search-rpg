#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../src/scenario.h"
#include "../src/json_loader.h"

void test_scenario() {
    Scenarios scenarios;
    load_scenarios(&scenarios, "scenarios.json");

    assert(strcmp(scenarios.scenario_list[0].name, "Job Fair") == 0);
    printf("test_scenario passed\n");
}

int main() {
    test_scenario();
    printf("All tests passed\n");
    return 0;
}
