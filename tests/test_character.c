#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "character.h"

void test_create_character(void) {
    Character character;
    create_character(&character, "Test", 100, 10, 5);

    CU_ASSERT_STRING_EQUAL(character.name, "Test");
    CU_ASSERT_EQUAL(character.hp, 100);
    CU_ASSERT_EQUAL(character.atk, 10);
    CU_ASSERT_EQUAL(character.def, 5);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Character Suite", 0, 0);

    CU_add_test(suite, "test_create_character", test_create_character);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
