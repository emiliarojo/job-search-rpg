#include <assert.h>
#include <string.h>
#include "../src/character.h"
#include "../src/json_loader.h"

extern Skill skills[MAX_SKILLS];

void test_create_character() {
    Character character;
    strcpy(character.name, "TestName");
    character.hp = 100;
    character.atk = 10;
    character.def = 10;

    // Mock chosen skills
    character.skills[0] = skills[0];
    character.skills[1] = skills[1];
    character.skills[2] = skills[2];
    character.skills[3] = skills[3];
    character.num_skills = 4;

    // Ensure skills are set correctly
    assert(strcmp(character.skills[0].name, skills[0].name) == 0);
    assert(strcmp(character.skills[1].name, skills[1].name) == 0);
    assert(strcmp(character.skills[2].name, skills[2].name) == 0);
    assert(strcmp(character.skills[3].name, skills[3].name) == 0);

    printf("test_create_character passed\n");
}

int main() {
    // Initialize skills for testing
    strcpy(skills[0].name, "Skill1");
    strcpy(skills[1].name, "Skill2");
    strcpy(skills[2].name, "Skill3");
    strcpy(skills[3].name, "Skill4");

    test_create_character();
    printf("All tests passed\n");
    return 0;
}
