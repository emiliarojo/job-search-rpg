#ifndef JSON_LOADER_H
#define JSON_LOADER_H

#include "character.h"
#include "enemy.h"
#include "scenario.h"

void load_skills(const char *filename);
void load_enemies(const char *filename);
void load_scenarios(Scenarios *scenarios, const char *filename);

#endif
