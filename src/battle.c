#include <stdio.h>
#include <stdlib.h>
#include "battle.h"
#include "queue.h"
#include "stack.h"
#include "character.h"
#include "enemy.h"

// Function to initiate a battle between the player and an enemy
void initiate_battle(Character *player, Enemy *enemy) {
    // Initialize the turn queue and action stack
    Queue queue;
    init_queue(&queue);
    Stack stack;
    init_stack(&stack);

    // Determine the turn order
    int player_turn = 1;
    enqueue(&queue, player_turn); // Player's turn
    enqueue(&queue, !player_turn); // Enemy's turn

    // Battle loop continues until either player or enemy HP drops to 0
    while (player->hp > 0 && enemy->hp > 0) {
        int current_turn = dequeue(&queue);
        if (current_turn == player_turn) {
            execute_player_turn(player, enemy, &stack); // Player's turn
        } else {
            execute_enemy_turn(player, enemy); // Enemy's turn
        }
        enqueue(&queue, current_turn); // Enqueue the current turn back
    }

    // Check the outcome of the battle
    if (player->hp > 0) {
        printf("You defeated the %s!\n", enemy->name);
    } else {
        printf("You were defeated by the %s.\n", enemy->name);
    }
}

// Function to execute the player's turn
void execute_player_turn(Character *player, Enemy *enemy, Stack *stack) {
    // Display player's available skills
    printf("Your turn! Choose a skill:\n");
    for (int i = 0; i < player->num_skills; i++) {
        printf("%d. %s - %s\n", i + 1, player->skills[i].name, player->skills[i].description);
    }

    // Get player's skill choice
    int choice;
    scanf("%d", &choice);
    choice -= 1;

    // Validate the chosen skill
    if (choice < 0 || choice >= player->num_skills) {
        printf("Invalid skill choice.\n");
        return;
    }

    // Apply the chosen skill's effect
    if (player->skills[choice].type == DIRECT_ATTACK) {
        int damage = (player->atk + player->skills[choice].modifier) - enemy->def;
        if (damage < 0) {
            damage = 0; // Ensure damage is not negative
        }
        enemy->hp -= damage;
        // printf("Damage dealt to enemy: %d\n", damage); // Debugging output
    } else if (player->skills[choice].type == TEMPORARY_MODIFIER) {
        player->atk += player->skills[choice].modifier;
        // printf("Temporary modifier applied, new player ATK: %d\n", player->atk); // Debugging output
    }
    push(stack, choice); // Push the chosen skill onto the stack

    // Display the outcome of the player's action
    if (enemy->hp > 0) {
        printf("You used %s! Enemy HP is now %d\n", player->skills[choice].name, enemy->hp);
    }
}

// Function to execute the enemy's turn
void execute_enemy_turn(Character *player, Enemy *enemy) {
    // printf("Enemy turn. Number of skills: %d\n", enemy->num_skills); // Debugging output
    if (enemy->num_skills == 0) {
        printf("Enemy has no skills to use.\n");
        return;
    }

    // Randomly select an enemy skill
    int skill_index = rand() % enemy->num_skills;
    Skill skill = enemy->skills[skill_index];

    // Apply the selected skill's effect
    int damage = 0;
    if (skill.type == DIRECT_ATTACK) {
        damage = (enemy->atk + skill.modifier) - player->def;
        if (damage < 0) {
            damage = 0; // Ensure damage is not negative
        }
        player->hp -= damage;
        // printf("Damage dealt to player: %d\n", damage); // Debugging output
    } else if (skill.type == TEMPORARY_MODIFIER) {
        enemy->atk += skill.modifier;
        // printf("Temporary modifier applied, new enemy ATK: %d\n", enemy->atk); // Debugging output
    }

    // Display the outcome of the enemy's action
    printf("%s uses %s! Your HP is now %d (Damage: %d)\n", enemy->name, skill.name, player->hp, damage);
}
