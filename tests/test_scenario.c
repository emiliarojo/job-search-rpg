#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "scenario.h"
#include "json_loader.h"

void test_load_scenarios(void) {
    ScenarioGraph graph;
    initialize_graph(&graph, 4);

    load_scenarios(&graph, "scenarios.json");

    CU_ASSERT_STRING_EQUAL(graph.scenarios[0].name, "Job Fair");
    CU_ASSERT_STRING_EQUAL(graph.scenarios[1].name, "Phone Interview");
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Scenario Suite", 0, 0);

    CU_add_test(suite, "test_load_scenarios", test_load_scenarios);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
