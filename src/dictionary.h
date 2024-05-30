#ifndef DICTIONARY_H
#define DICTIONARY_H

#define MAX_ITEMS 100

typedef struct {
    char key[50];
    int value;
} DictItem;

typedef struct {
    DictItem items[MAX_ITEMS];
    int size;
} Dictionary;

void init_dictionary(Dictionary *dict);
void add_to_dictionary(Dictionary *dict, const char *key, int value);
int get_from_dictionary(Dictionary *dict, const char *key);

#endif
