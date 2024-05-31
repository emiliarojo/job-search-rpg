#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "enemy.h"
#include "stack.h"

// Function to initiate a battle between the player and an enemy
void initiate_battle(Character *player, Enemy *enemy);

// Function to execute the player's turn
void execute_player_turn(Character *player, Enemy *enemy, Stack *stack, int *time_strike_used);

// Function to execute the enemy's turn
void execute_enemy_turn(Character *player, Enemy *enemy);

#endif
