#include <stdio.h>
#include <string.h>
#include "character.h"

extern Skill skills[MAX_SKILLS];

void create_character(Character *character) {
    printf("Enter your character's name: ");
    scanf("%s", character->name);
    character->hp = 100;
    character->atk = 10;
    character->def = 10;

    int chosen_skills[4] = { -1, -1, -1, -1 }; // Array to store chosen skill indices

    printf("Choose 4 skills for your character:\n");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (strlen(skills[i].name) > 0) {
            printf("%d. %s - %s\n", i + 1, skills[i].name, skills[i].description);
        }
    }

    for (int i = 0; i < 4; i++) {
        int choice;
        int valid_choice = 0;

        while (!valid_choice) {
            printf("Choose skill %d: ", i + 1);
            scanf("%d", &choice);
            choice -= 1;

            valid_choice = 1;
            for (int j = 0; j < i; j++) {
                if (chosen_skills[j] == choice) {
                    printf("Skill already chosen. Please choose a different skill.\n");
                    valid_choice = 0;
                    break;
                }
            }

            if (valid_choice) {
                chosen_skills[i] = choice;
                character->skills[i] = skills[choice];
            }
        }
    }
    character->num_skills = 4;
}
