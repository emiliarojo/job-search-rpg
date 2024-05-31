#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "battle.h"
#include "character.h"
#include "enemy.h"
#include "stack.h"
#include "queue.h"

void test_execute_battle(void) {
    Character player;
    create_character(&player, "Player", 100, 10, 5);

    Enemy enemy;
    create_enemy(&enemy, "Enemy", 50, 8, 3);

    Stack player_moves;
    initialize_stack(&player_moves, 10);

    Queue turn_queue;
    initialize_queue(&turn_queue, 10);

    execute_battle(&player, &enemy, &player_moves, &turn_queue);

    CU_ASSERT_TRUE(player.hp > 0);
    CU_ASSERT_TRUE(enemy.hp <= 0);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Battle Suite", 0, 0);

    CU_add_test(suite, "test_execute_battle", test_execute_battle);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
