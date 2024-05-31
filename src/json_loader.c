#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json_loader.h"
#include "cJSON.h"
#include "character.h"
#include "enemy.h"

// Array to hold all possible skills
Skill skills[MAX_SKILLS];

// Function to load skills from a JSON file
void load_skills(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = (char *)malloc(length + 1);
    fread(data, 1, length, file);
    fclose(file);

    // Parse the JSON data
    cJSON *json = cJSON_Parse(data);
    if (!json) {
        perror("Failed to parse JSON");
        free(data);
        return;
    }

    // Load skills from JSON array
    int count = cJSON_GetArraySize(json);
    for (int i = 0; i < count && i < MAX_SKILLS; i++) {
        cJSON *item = cJSON_GetArrayItem(json, i);
        strcpy(skills[i].name, cJSON_GetObjectItem(item, "name")->valuestring);
        strcpy(skills[i].description, cJSON_GetObjectItem(item, "description")->valuestring);
        skills[i].type = strcmp(cJSON_GetObjectItem(item, "type")->valuestring, "TEMPORARY_MODIFIER") == 0 ? TEMPORARY_MODIFIER : DIRECT_ATTACK;
        skills[i].modifier = cJSON_GetObjectItem(item, "modifier")->valueint;
        skills[i].duration = cJSON_GetObjectItem(item, "duration")->valueint;
    }

    free(data);
    cJSON_Delete(json);
}

// Function to load scenarios from a JSON file
void load_scenarios(Scenarios *scenarios, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = (char *)malloc(length + 1);
    fread(data, 1, length, file);
    fclose(file);

    // Parse the JSON data
    cJSON *json = cJSON_Parse(data);
    if (!json) {
        perror("Failed to parse JSON");
        free(data);
        return;
    }

    // Load scenarios from JSON array
    int scenario_count = cJSON_GetArraySize(json);
    scenarios->scenario_count = scenario_count;

    for (int i = 0; i < scenario_count; i++) {
        cJSON *scenario_json = cJSON_GetArrayItem(json, i);
        Scenario *scenario = &scenarios->scenario_list[i];

        // Load scenario details
        strcpy(scenario->name, cJSON_GetObjectItem(scenario_json, "name")->valuestring);
        strcpy(scenario->description, cJSON_GetObjectItem(scenario_json, "description")->valuestring);

        cJSON *decisions_json = cJSON_GetObjectItem(scenario_json, "decisions");
        int decision_count = cJSON_GetArraySize(decisions_json);
        scenario->num_decisions = decision_count;

        for (int j = 0; j < decision_count; j++) {
            cJSON *decision_json = cJSON_GetArrayItem(decisions_json, j);
            Decision *decision = &scenario->decisions[j];

            // Load decision details
            strcpy(decision->text, cJSON_GetObjectItem(decision_json, "text")->valuestring);
            strcpy(decision->pre_battle_text, cJSON_GetObjectItem(decision_json, "pre_battle_text")->valuestring);
            strcpy(decision->post_battle_text, cJSON_GetObjectItem(decision_json, "post_battle_text")->valuestring);

            cJSON *enemies_json = cJSON_GetObjectItem(decision_json, "enemies");
            int enemy_count = cJSON_GetArraySize(enemies_json);
            decision->num_enemies = enemy_count;

            // Load enemies for the decision
            for (int k = 0; k < enemy_count; k++) {
                cJSON *enemy_json = cJSON_GetArrayItem(enemies_json, k);
                strcpy(decision->enemies[k].name, cJSON_GetObjectItem(enemy_json, "name")->valuestring);
                decision->enemies[k].hp = cJSON_GetObjectItem(enemy_json, "hp")->valueint;
                decision->enemies[k].atk = cJSON_GetObjectItem(enemy_json, "atk")->valueint;
                decision->enemies[k].def = cJSON_GetObjectItem(enemy_json, "def")->valueint;

                cJSON *skills_json = cJSON_GetObjectItem(enemy_json, "skills");
                int skill_count = cJSON_GetArraySize(skills_json);
                for (int s = 0; s < skill_count && s < MAX_ENEMY_SKILLS; s++) {
                    cJSON *skill_item = cJSON_GetArrayItem(skills_json, s);
                    strcpy(decision->enemies[k].skills[s].name, cJSON_GetObjectItem(skill_item, "name")->valuestring);
                    strcpy(decision->enemies[k].skills[s].description, cJSON_GetObjectItem(skill_item, "description")->valuestring);
                    decision->enemies[k].skills[s].type = strcmp(cJSON_GetObjectItem(skill_item, "type")->valuestring, "TEMPORARY_MODIFIER") == 0 ? TEMPORARY_MODIFIER : DIRECT_ATTACK;
                    decision->enemies[k].skills[s].modifier = cJSON_GetObjectItem(skill_item, "modifier")->valueint;
                    decision->enemies[k].skills[s].duration = cJSON_GetObjectItem(skill_item, "duration")->valueint;
                }
                decision->enemies[k].num_skills = skill_count;
            }

            decision->next_scenario = cJSON_GetObjectItem(decision_json, "next_scenario")->valueint;
        }
    }

    free(data);
    cJSON_Delete(json);
}
