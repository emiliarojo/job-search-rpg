CC = gcc
CFLAGS = -Wall -g
SRC = src/main.c src/character.c src/battle.c src/scenario.c src/json_loader.c src/queue.c src/stack.c src/graph.c src/dictionary.c src/enemy.c src/cJSON.c
OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
TESTS = tests/test_character.c tests/test_queue.c tests/test_stack.c

all: job-search-rpg

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

job-search-rpg: $(OBJ)
	$(CC) $(CFLAGS) -o job-search-rpg $(OBJ)

clean:
	rm -f job-search-rpg $(OBJ_DIR)/*.o

test: $(TESTS)
	$(CC) $(CFLAGS) -o test_character tests/test_character.c src/character.c
	./test_character
	$(CC) $(CFLAGS) -o test_queue tests/test_queue.c src/queue.c
	./test_queue
	$(CC) $(CFLAGS) -o test_stack tests/test_stack.c src/stack.c
	./test_stack
