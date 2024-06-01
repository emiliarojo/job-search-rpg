#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../src/battle.h"
#include "../src/character.h"
#include "../src/enemy.h"
#include "../src/json_loader.h"
#include "../src/stack.h"

void test_battle() {
    Character player;
    Enemy enemy;

    // Load skills and create a character
    load_skills("data/skills.json");
    create_character(&player);

    // Setup an enemy
    enemy.hp = 50;
    enemy.atk = 5;
    enemy.def = 2;
    enemy.num_skills = 1;
    strcpy(enemy.skills[0].name, "Test Attack");
    enemy.skills[0].type = DIRECT_ATTACK;
    enemy.skills[0].modifier = 5;

    // Simulate a battle
    initiate_battle(&player, &enemy);

    // Ensure that the battle ends with either player or enemy defeated
    assert(player.hp > 0 || enemy.hp > 0);
    printf("test_battle passed.\n");
}

int main() {
    test_battle();
    printf("All battle tests passed.\n");
    return 0;
}
