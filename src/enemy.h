#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#define MAX_ENEMIES 10
#define MAX_ENEMY_SKILLS 4

typedef struct {
    char name[50];
    int hp;
    int atk;
    int def;
    Skill skills[MAX_ENEMY_SKILLS];
    int num_skills;
} Enemy;

extern Enemy enemies[MAX_ENEMIES];

#endif
