#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "graph.h"

void test_graph_operations(void) {
    ScenarioGraph graph;
    initialize_graph(&graph, 4);

    add_scenario(&graph, 0, "Scenario 1");
    add_scenario(&graph, 1, "Scenario 2");
    add_scenario(&graph, 2, "Scenario 3");
    add_scenario(&graph, 3, "Scenario 4");

    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);

    CU_ASSERT_STRING_EQUAL(graph.scenarios[0].name, "Scenario 1");
    CU_ASSERT_EQUAL(graph.edges[0][1], 1);
    CU_ASSERT_EQUAL(graph.edges[1][2], 1);
    CU_ASSERT_EQUAL(graph.edges[2][3], 1);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Graph Suite", 0, 0);

    CU_add_test(suite, "test_graph_operations", test_graph_operations);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
