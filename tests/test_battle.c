#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../src/battle.h"
#include "../src/character.h"
#include "../src/enemy.h"

void test_battle() {
    Character player;
    strcpy(player.name, "Player");
    player.hp = 100;
    player.atk = 10;
    player.def = 5;

    Enemy enemy;
    strcpy(enemy.name, "Enemy");
    enemy.hp = 50;
    enemy.atk = 5;
    enemy.def = 2;

    initiate_battle(&player, &enemy);
    printf("test_battle passed\n");
}

int main() {
    test_battle();
    printf("All tests passed\n");
    return 0;
}
