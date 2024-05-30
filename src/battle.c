#include <stdio.h>
#include <stdlib.h>
#include "battle.h"
#include "queue.h"
#include "stack.h"
#include "character.h"
#include "enemy.h"

void initiate_battle(Character *player, Enemy *enemy) {
    Queue queue;
    init_queue(&queue);
    Stack stack;
    init_stack(&stack);

    int player_turn = 1;
    enqueue(&queue, player_turn);
    enqueue(&queue, !player_turn);

    while (player->hp > 0 && enemy->hp > 0) {
        int current_turn = dequeue(&queue);
        if (current_turn == player_turn) {
            execute_player_turn(player, enemy, &stack);
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

void execute_player_turn(Character *player, Enemy *enemy, Stack *stack) {
    printf("Your turn! Choose a skill:\n");
    for (int i = 0; i < player->num_skills; i++) {
        printf("%d. %s - %s\n", i + 1, player->skills[i].name, player->skills[i].description);
    }

    int choice;
    scanf("%d", &choice);
    choice -= 1;

    // Apply skill effect
    if (player->skills[choice].type == DIRECT_ATTACK) {
        int damage = (player->atk + player->skills[choice].modifier) - enemy->def;
        if (damage > 0) {
            enemy->hp -= damage;
        } else {
            damage = 0; // Ensure damage is not negative
        }
    } else if (player->skills[choice].type == TEMPORARY_MODIFIER) {
        player->atk += player->skills[choice].modifier;
    }
    push(stack, choice);

    printf("You used %s! Enemy HP is now %d\n", player->skills[choice].name, enemy->hp);
}

void execute_enemy_turn(Character *player, Enemy *enemy) {
    int skill_index = rand() % enemy->num_skills;
    Skill skill = enemy->skills[skill_index];

    int damage = 0;
    if (skill.type == DIRECT_ATTACK) {
        damage = (enemy->atk + skill.modifier) - player->def;
        if (damage > 0) {
            player->hp -= damage;
        } else {
            damage = 0; // Ensure damage is not negative
        }
    } else if (skill.type == TEMPORARY_MODIFIER) {
        enemy->atk += skill.modifier;
    }

    printf("Enemy uses %s! Your HP is now %d (Damage: %d)\n", skill.name, player->hp, damage);
}
