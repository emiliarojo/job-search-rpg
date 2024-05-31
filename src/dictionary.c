#include <string.h>
#include "dictionary.h"

void init_dictionary(SkillDictionary *dict) {
    dict->size = 0;
}

void increment_skill_usage(SkillDictionary *dict, const char *skill_name) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->skills[i].skill_name, skill_name) == 0) {
            dict->skills[i].usage_count++;
            return;
        }
    }
    strcpy(dict->skills[dict->size].skill_name, skill_name);
    dict->skills[dict->size].usage_count = 1;
    dict->size++;
}

int get_skill_usage(SkillDictionary *dict, const char *skill_name) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->skills[i].skill_name, skill_name) == 0) {
            return dict->skills[i].usage_count;
        }
    }
    return 0;
}
