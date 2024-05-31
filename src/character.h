#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_SKILLS 10 // Maximum number of skills

// Definition of the Skill structure
typedef struct {
    char name[50];
    char description[200];
    enum { TEMPORARY_MODIFIER, DIRECT_ATTACK } type;
    int modifier;
    int duration;
} Skill;

// Definition of the Character structure
typedef struct {
    char name[50];
    int hp;
    int atk;
    int def;
    Skill skills[MAX_SKILLS];
    int num_skills;
} Character;

// External declaration of the skills array
extern Skill skills[MAX_SKILLS];

// Function to create and initialize a character
void create_character(Character *character);

#endif
