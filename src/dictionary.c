#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

void init_dictionary(Dictionary *dict) {
    dict->size = 0;
}

void add_to_dictionary(Dictionary *dict, const char *key, int value) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            dict->items[i].value += value;
            return;
        }
    }
    strcpy(dict->items[dict->size].key, key);
    dict->items[dict->size].value = value;
    dict->size++;
}

int get_from_dictionary(Dictionary *dict, const char *key) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            return dict->items[i].value;
        }
    }
    return 0;
}
