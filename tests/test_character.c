#include <stdio.h>
#include <assert.h>
#include "../src/character.h"
#include "../src/json_loader.h"

void test_create_character() {
    Character player;
    load_skills("data/skills.json");
    create_character(&player);

    // Check if character name is set
    assert(player.name[0] != '\0');

    // Check if character stats are set correctly
    assert(player.hp == 100);
    assert(player.atk == 10);
    assert(player.def == 10);

    // Check if 4 skills are assigned
    assert(player.num_skills == 4);
    printf("test_create_character passed.\n");
}

int main() {
    test_create_character();
    printf("All character tests passed.\n");
    return 0;
}
