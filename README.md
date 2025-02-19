# BattleShip Game

## Overview
The BattleShip Game is a console-based implementation of the classic Battleship game, developed as part of an Object-Oriented Programming course at AGH University. The game allows two players to compete by strategically placing ships on a board and attempting to sink each other's fleet.

## Features
- **Two-player mode**: Players take turns attacking each other's ships.
- **Console-based UI**: Simple text input for placing ships and attacking.
- **Turn-based mechanics**: Players alternate turns, and successful hits allow for additional moves.
- **Win conditions**: The first player to sink all opponent's ships wins the game.
- **Custom ship placement**: Players place their ships by specifying coordinates and orientation.

## How to Play
1. **Ship Placement**:
   - Players place their ships in order from largest to smallest.
   - Placement format: `(letter, number, orientation)`, e.g., `a5 H` for a horizontal placement.
   - Letters range from `a-j`, numbers from `1-10`.
   - Orientation options: `H` (horizontal) or `V` (vertical).
   
2. **Gameplay**:
   - Players take turns attacking by selecting coordinates (e.g., `b3`).
   - A hit allows the player to take another turn.
   - The game ends when one player sinks all opponent's ships.

## Compilation & Requirements
- **Operating System**: Windows (requires Windows API)
- **Compilation**: Standard C++ compilation using any compatible compiler.
- **Dependencies**: Uses Windows API.
  - [Windows API Documentation](https://learn.microsoft.com/en-us/windows/win32/apiindex/windows-api-list)

## Source Files
The project consists of the following source files:
- **BattleShip.h / BattleShip.cpp** - Main gameplay logic.
- **Board.h / Board.cpp** - Manages the game board.
- **BoardShips.h / BoardShips.cpp** - Handles logical ship placement.
- **Player.h / Player.cpp** - Manages player data.
- **Ship.h / Ship.cpp** - Represents ships and their properties.

## Class Descriptions
### Board Class
- Manages the game board state.
- Methods include setting/updating board configurations, checking ship positions, and rendering the board.

### Player Class
- Stores player information and turn states.
- Methods handle player actions and game progress tracking.

### BoardShips Class
- Manages the logical representation of ship placement.
- Ensures correct placement and prevents overlapping.

### Ship Class
- Represents an individual ship with properties like position and size.

## Planned Improvements
- **Graphical Interface**: Implement a GUI for better interaction.
- **AI Opponent**: Allow single-player mode against a computer.
- **Collision Prevention**: Prevent ships from being placed adjacent to each other.
- **Game History**: Add logging for past games.

## Author
Jakub Konior

## License
This project is open-source and available for educational use.

