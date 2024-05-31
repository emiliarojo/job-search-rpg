#ifndef JSON_LOADER_H
#define JSON_LOADER_H

#include "character.h"
#include "scenario.h"

#define MAX_SKILLS 10 // Maximum number of skills
#define MAX_ENEMIES 10 // Maximum number of enemies

// External declarations of global skill and enemy arrays
extern Skill skills[MAX_SKILLS];
extern Enemy enemies[MAX_ENEMIES];

// Function to load skills from a JSON file
void load_skills(const char *filename);

// Function to load scenarios from a JSON file
void load_scenarios(Scenarios *scenarios, const char *filename);

#endif
