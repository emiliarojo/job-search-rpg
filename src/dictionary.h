#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX_SKILLS 10

typedef struct {
    char skill_name[50];
    int usage_count;
} SkillUsage;

typedef struct {
    SkillUsage skills[MAX_SKILLS];
    int size;
} SkillDictionary;

void init_dictionary(SkillDictionary *dict);
void increment_skill_usage(SkillDictionary *dict, const char *skill_name);
int get_skill_usage(SkillDictionary *dict, const char *skill_name);

#endif
