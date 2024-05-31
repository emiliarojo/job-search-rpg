#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#define MAX_ENEMIES 10 // Maximum number of enemies in the game
#define MAX_ENEMY_SKILLS 4 // Maximum number of skills an enemy can have

// Definition of the Enemy structure
typedef struct {
    char name[50];
    int hp;
    int atk;
    int def;
    Skill skills[MAX_ENEMY_SKILLS];
    int num_skills;
} Enemy;

// External declaration of the enemies array
extern Enemy enemies[MAX_ENEMIES];

#endif
