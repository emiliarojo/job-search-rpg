#include <stdio.h>
#include <stdlib.h>
#include "battle.h"
#include "queue.h"
#include "stack.h"
#include "character.h"
#include "enemy.h"

// Function to initiate a battle between the player and an enemy
void initiate_battle(Character *player, Enemy *enemy) {
    Queue queue;
    init_queue(&queue);
    Stack stack;
    init_stack(&stack);

    int player_turn = 1;
    enqueue(&queue, player_turn);
    enqueue(&queue, !player_turn);

    int time_strike_used = 0;

    while (player->hp > 0 && enemy->hp > 0) {
        int current_turn = dequeue(&queue);
        if (current_turn == player_turn) {
            execute_player_turn(player, enemy, &stack, &time_strike_used); // Pass the flag to check Time Strike
        } else {
            execute_enemy_turn(player, enemy);
        }
        enqueue(&queue, current_turn);
    }

    if (player->hp > 0) {
        printf("You defeated the %s!\n", enemy->name);
    } else {
        printf("You were defeated by the %s.\n", enemy->name);
    }
}

// Function to execute the player's turn
void execute_player_turn(Character *player, Enemy *enemy, Stack *stack, int *time_strike_used) {
    printf("Your turn! Choose a skill:\n");
    for (int i = 0; i < player->num_skills; i++) {
        printf("%d. %s - %s\n", i + 1, player->skills[i].name, player->skills[i].description);
    }

    if (!(*time_strike_used)) {
        printf("%d. Time Strike\n", player->num_skills + 1);
    }

    int choice;
    scanf("%d", &choice);
    choice -= 1;

    if (choice < 0 || choice >= player->num_skills + 1 || (choice == player->num_skills && *time_strike_used)) {
        printf("Invalid skill choice.\n");
        return;
    }

    if (choice == player->num_skills) {
        // Time Strike logic
        if (is_stack_empty(stack)) {
            printf("No previous moves to use Time Strike.\n");
            return;
        }
        int move_index = rand() % (stack->top + 1);
        int skill_choice = stack->data[move_index];
        int damage = (player->atk + player->skills[skill_choice].modifier) * 2 - enemy->def;
        if (damage < 0) {
            damage = 0;
        }
        enemy->hp -= damage;
        printf("Time Strike! You used %s with double power! Enemy HP is now %d\n", player->skills[skill_choice].name, enemy->hp);
        *time_strike_used = 1;
    } else {
        // Normal skill logic
        if (player->skills[choice].type == DIRECT_ATTACK) {
            int damage = (player->atk + player->skills[choice].modifier) - enemy->def;
            if (damage < 0) {
                damage = 0;
            }
            enemy->hp -= damage;
        } else if (player->skills[choice].type == TEMPORARY_MODIFIER) {
            player->atk += player->skills[choice].modifier;
        }
        push(stack, choice);
        if (enemy->hp > 0) {
            printf("You used %s! Enemy HP is now %d\n", player->skills[choice].name, enemy->hp);
        }
    }
}

// Function to execute the enemy's turn
void execute_enemy_turn(Character *player, Enemy *enemy) {
    if (enemy->num_skills == 0) {
        printf("Enemy has no skills to use.\n");
        return;
    }

    int skill_index = rand() % enemy->num_skills;
    Skill skill = enemy->skills[skill_index];

    int damage = 0;
    if (skill.type == DIRECT_ATTACK) {
        damage = (enemy->atk + skill.modifier) - player->def;
        if (damage < 0) {
            damage = 0;
        }
        player->hp -= damage;
    } else if (skill.type == TEMPORARY_MODIFIER) {
        enemy->atk += skill.modifier;
    }

    printf("%s uses %s! Your HP is now %d (Damage: %d)\n", enemy->name, skill.name, player->hp, damage);
}
