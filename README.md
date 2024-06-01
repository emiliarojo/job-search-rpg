# Job Search RPG

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Setup](#setup)
- [Usage](#usage)
- [Game Mechanics](#game-mechanics)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Introduction
**Job Search RPG** is an interactive text-based game where you navigate through various job search scenarios, make strategic decisions, and battle recruiters and interviewers. Utilize your skills to defeat enemies and progress through the game, ultimately landing your dream job.

## Features
- Interactive text-based gameplay
- Multiple job search scenarios and decisions
- Strategic battle system with skills and modifiers
- Save and load game functionality
- Unit tests to ensure code reliability

## Setup
### Prerequisites
Ensure you have the following installed:
- GCC (GNU Compiler Collection)
- Make

### Installation
1. Clone the repository:
    ```
    git clone https://github.com/emiliarojo/job-search-rpg.git
    cd job-search-rpg
    ```

2. Compile the game:
    ```
    make
    ```

### Directory Structure
```plaintext
job-search-rpg/
├── data/
│   ├── scenarios.json
│   └── skills.json
├── doc/
├── obj/
├── src/
│   ├── battle.c
│   ├── battle.h
│   ├── character.c
│   ├── character.h
│   ├── cJSON.c
│   ├── cJSON.h
│   ├── dictionary.c
│   ├── dictionary.h
│   ├── enemy.c
│   ├── enemy.h
│   ├── graph.c
│   ├── graph.h
│   ├── json_loader.c
│   ├── json_loader.h
│   ├── main.c
│   ├── queue.c
│   ├── queue.h
│   ├── scenario.c
│   ├── scenario.h
│   ├── stack.c
│   └── stack.h
├── tests/
│   ├── test_battle.c
│   ├── test_character.c
│   ├── test_queue.c
│   ├── test_scenario.c
│   └── test_stack.c
├── Makefile
├── README.md
├── savegame.txt
└── ...
```

## Usage
To start the game, run the compiled binary:
```
./job-search-rpg
```

Follow the on-screen prompts to create your character, navigate through scenarios, and engage in battles.

## Game Mechanics
### Character Creation
- Choose a name for your character.
- Select 4 out of 10 possible skills.

### Skills
Skills have different effects such as increasing attack (ATK), defense (DEF), or dealing direct damage.

### Scenarios
Navigate through various job search scenarios. Each scenario presents different decisions and potential battles.

### Battles
Engage in turn-based battles with recruiters and interviewers. Use your skills strategically to defeat them.

## Testing
### Running Tests
Unit tests are included to ensure code reliability. To compile and run the tests, use:
```
make test
```

### Tests Overview
- **Character Tests**: Validate character creation and attributes.
- **Battle Tests**: Ensure battle mechanics work as expected.
- **Scenario Tests**: Verify scenario navigation and decision impacts.
- **Queue Tests**: Test queue operations.
- **Stack Tests**: Test stack operations.
