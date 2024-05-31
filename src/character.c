#include <stdio.h>
#include <string.h>
#include "character.h"

extern Skill skills[MAX_SKILLS];

// Function to create and initialize a player character
void create_character(Character *character) {
    // Prompt the user to enter the character's name
    printf("Enter your character's name: ");
    scanf("%s", character->name);

    // Set default character stats
    character->hp = 100;
    character->atk = 10;
    character->def = 10;

    // Array to keep track of chosen skills
    int chosen_skills[4] = { -1, -1, -1, -1 };

    // Prompt the user to choose 4 skills for the character
    printf("Choose 4 skills for your character:\n");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (strlen(skills[i].name) > 0) {
            printf("%d. %s - %s\n", i + 1, skills[i].name, skills[i].description);
        }
    }

    // Loop to select 4 unique skills
    for (int i = 0; i < 4; i++) {
        int choice;
        int valid_choice = 0;

        while (!valid_choice) {
            // Prompt for skill choice
            printf("Choose skill %d: ", i + 1);
            scanf("%d", &choice);
            choice -= 1;

            // Validate the chosen skill
            if (choice < 0 || choice >= MAX_SKILLS || strlen(skills[choice].name) == 0) {
                printf("Invalid choice. Please choose a different skill.\n");
                continue;
            }

            valid_choice = 1;
            // Check if the skill was already chosen
            for (int j = 0; j < i; j++) {
                if (chosen_skills[j] == choice) {
                    printf("Skill already chosen. Please choose a different skill.\n");
                    valid_choice = 0;
                    break;
                }
            }

            // Assign the chosen skill to the character if valid
            if (valid_choice) {
                chosen_skills[i] = choice;
                character->skills[i] = skills[choice];
            }
        }
    }
    character->num_skills = 4; // Set the number of skills for the character
}
