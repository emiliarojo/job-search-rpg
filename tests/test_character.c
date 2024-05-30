#include <assert.h>
#include "character.h"

void test_create_character() {
    Character player;
    create_character(&player);
    assert(player.hp == 100);
    assert(player.atk == 10);
    assert(player.def == 10);
}

int main() {
    test_create_character();
    printf("All tests passed.\n");
    return 0;
}
