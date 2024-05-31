# Job Search RPG

## Table of Contents

1. [Introduction](#introduction)
2. [Team Members](#team-members)
3. [Game Description](#game-description)
4. [Project Structure](#project-structure)
5. [How to Compile and Run](#how-to-compile-and-run)
6. [Features](#features)
7. [Data Structures and Algorithms](#data-structures-and-algorithms)
8. [Unit Tests](#unit-tests)

## Introduction

Job Search RPG is a turn-based role-playing game developed for the Data Structures and Algorithms II course. The game runs on the terminal and is developed in C. Players navigate through different scenarios, make decisions, and engage in battles using a character with unique skills.

## Game Description

In Job Search RPG, players assume the role of a job seeker navigating various scenarios related to job searching and interviews. The game involves creating a character, selecting skills, and battling different types of enemies (recruiters, interviewers, HR managers) to progress through the story.

## Project Structure

```
job-search-rpg/
│
├── src/
│   ├── main.c
│   ├── character.c
│   ├── character.h
│   ├── battle.c
│   ├── battle.h
│   ├── scenario.c
│   ├── scenario.h
│   ├── json_loader.c
│   ├── json_loader.h
│   ├── queue.c
│   ├── queue.h
│   ├── stack.c
│   ├── stack.h
│   ├── graph.c
│   ├── graph.h
│   ├── dictionary.c
│   ├── dictionary.h
│   ├── enemy.c
│   ├── enemy.h
│   ├── cJSON.c
|   └── cJSON.h
│
├── tests/
│   ├── test_character.c
│   ├── test_battle.c
│   └── test_scenario.c
│
├── data/
│   ├── scenarios.json
│   ├── enemies.json
│   └── skills.json
│
├── Makefile
└── README.md
```

## How to Compile and Run

1. **Compile the game:**
   ```sh
   make
   ```

2. **Run the game:**
   ```sh
   ./job-search-rpg
   ```

3. **Run the unit tests:**
   ```sh
   make test
   ```

## Features

### Mandatory Objectives

1. **Character Creation:**
   - Users can create a character with attributes such as name, HP, ATK, DEF, and a set of 4 skills.

2. **Scenarios and Narrative:**
   - The game includes 4 interconnected scenarios, each presenting a narrative and decisions affecting the story.

3. **Graph-Based World Navigation:**
   - Scenarios are connected in a graph structure allowing navigation between them.

4. **Turn-Based Battle System:**
   - Implemented a queue-based turn order system for battles.
   - Includes a special move "Time Strike" using a stack to repeat a previous move with double power.

5. **Enemy Types:**
   - Multiple types of enemies with unique attacks are implemented.

### Desirable Objectives

1. **Data Loading:**
   - Character, scenarios, skills, and enemies are loaded from JSON files.

2. **Unit Tests:**
   - Implemented unit tests for critical functions using data structures.


### Optional Objectives

1. **Improved UI/UX:**
   - Enhanced user experience through clear prompts and feedback.

## Data Structures and Algorithms

1. **Graph:**
   - Used for scenario navigation.
   - Implemented as an adjacency list.

2. **Queue:**
   - Used for managing turn order in battles.

3. **Stack:**
   - Used for the "Time Strike" move to repeat previous actions.


## Unit Tests

Unit tests have been implemented for the following functionalities:
- Character creation and initialization.
- Scenario loading and navigation.
- Battle system and turn management.

To run the tests, execute:
```
make test
```

## Usage Tracking

A dictionary structure tracks the usage count of each skill, providing insights into the most used skills during gameplay.
