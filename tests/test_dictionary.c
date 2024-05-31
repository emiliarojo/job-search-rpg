#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "dictionary.h"

void test_dictionary_operations(void) {
    Dictionary dict;
    initialize_dictionary(&dict);

    add_to_dictionary(&dict, "skill1");
    add_to_dictionary(&dict, "skill2");
    add_to_dictionary(&dict, "skill1");

    CU_ASSERT_EQUAL(get_from_dictionary(&dict, "skill1"), 2);
    CU_ASSERT_EQUAL(get_from_dictionary(&dict, "skill2"), 1);
    CU_ASSERT_EQUAL(get_from_dictionary(&dict, "skill3"), 0);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Dictionary Suite", 0, 0);

    CU_add_test(suite, "test_dictionary_operations", test_dictionary_operations);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
