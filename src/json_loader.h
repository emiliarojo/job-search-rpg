#ifndef JSON_LOADER_H
#define JSON_LOADER_H

#include "character.h"
#include "scenario.h"

#define MAX_SKILLS 10
#define MAX_ENEMIES 10

extern Skill skills[MAX_SKILLS];
extern Enemy enemies[MAX_ENEMIES];

void load_skills(const char *filename);
void load_scenarios(Scenarios *scenarios, const char *filename);

#endif
