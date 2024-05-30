#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_SKILLS 10

typedef struct {
    char name[50];
    char description[200];
    enum { TEMPORARY_MODIFIER, DIRECT_ATTACK } type;
    int modifier;
    int duration;
} Skill;

typedef struct {
    char name[50];
    int hp;
    int atk;
    int def;
    Skill skills[MAX_SKILLS];
    int num_skills;
} Character;

extern Skill skills[MAX_SKILLS];

void create_character(Character *character);

#endif
