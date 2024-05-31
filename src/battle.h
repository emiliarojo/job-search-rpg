#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "enemy.h"
#include "stack.h"

// Function to initiate a battle between the player and an enemy
void initiate_battle(Character *player, Enemy *enemy);

// Function to execute the player's turn in a battle
void execute_player_turn(Character *player, Enemy *enemy, Stack *stack);

// Function to execute the enemy's turn in a battle
void execute_enemy_turn(Character *player, Enemy *enemy);

#endif
