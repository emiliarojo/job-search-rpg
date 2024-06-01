CC = gcc
CFLAGS = -Wall -g
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
BIN = job-search-rpg

SRC_FILES = $(SRC_DIR)/character.c $(SRC_DIR)/battle.c $(SRC_DIR)/scenario.c $(SRC_DIR)/json_loader.c $(SRC_DIR)/queue.c $(SRC_DIR)/stack.c $(SRC_DIR)/graph.c $(SRC_DIR)/dictionary.c $(SRC_DIR)/enemy.c $(SRC_DIR)/cJSON.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(BIN)

$(BIN): $(OBJ_FILES) $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c -o $@ $<

test_character: $(TEST_DIR)/test_character.c $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(TEST_DIR)/test_character.c $(OBJ_FILES)

test_battle: $(TEST_DIR)/test_battle.c $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(TEST_DIR)/test_battle.c $(OBJ_FILES)

test_scenario: $(TEST_DIR)/test_scenario.c $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(TEST_DIR)/test_scenario.c $(OBJ_FILES)

test_queue: $(TEST_DIR)/test_queue.c $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(TEST_DIR)/test_queue.c $(OBJ_FILES)

test_stack: $(TEST_DIR)/test_stack.c $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(TEST_DIR)/test_stack.c $(OBJ_FILES)

test: test_character test_battle test_scenario test_queue test_stack
	./test_character
	./test_battle
	./test_scenario
	./test_queue
	./test_stack

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN) test_character test_battle test_scenario test_queue test_stack
