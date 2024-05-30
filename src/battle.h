#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "enemy.h"
#include "stack.h"

void initiate_battle(Character *player, Enemy *enemy);
void execute_player_turn(Character *player, Enemy *enemy, Stack *stack);
void execute_enemy_turn(Character *player, Enemy *enemy);

#endif
