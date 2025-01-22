# Morpion (Tic-Tac-Toe) Game in C

Welcome to the **Morpion Game**, a console-based implementation of the classic Tic-Tac-Toe game written in C. This project allows users to play either against another human player or an AI opponent with three levels of difficulty: **Easy**, **Normal**, and **Hard**.

The game emphasizes customization and user experience, allowing players to personalize the game symbols and their colors. Additionally, the project includes essential features such as saving and loading games, enabling players to continue their progress seamlessly.

---
# Screenshots

Here are some styled screenshots of the project:

<div style="display: flex; flex-wrap: wrap; gap: 20px; justify-content: center;">

  <img src="https://github.com/user-attachments/assets/736734b0-411b-41ad-9f1d-dade7da2ed78" alt="Screenshot 1" style="width: 300px; border: 2px solid #ddd; border-radius: 10px; box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);">
  
  <img src="https://github.com/user-attachments/assets/e994521e-cb16-49a9-a391-a755b9232065" alt="Screenshot 2" style="width: 300px; border: 2px solid #ddd; border-radius: 10px; box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);">
  
  <img src="https://github.com/user-attachments/assets/3244b629-090b-4821-9b17-2198a29cc351" alt="Screenshot 3" style="width: 300px; border: 2px solid #ddd; border-radius: 10px; box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);">
  
  <img src="https://github.com/user-attachments/assets/c850cd4e-15ac-46a0-a142-4b31a55d0af9" alt="Screenshot 4" style="width: 300px; border: 2px solid #ddd; border-radius: 10px; box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);">
  
  <img src="https://github.com/user-attachments/assets/c8a0027a-c2a4-4843-87ff-3548eb19135f" alt="Screenshot 5" style="width: 300px; border: 2px solid #ddd; border-radius: 10px; box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);">
  
</div>


## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Modes](#game-modes)
- [Customization](#customization)
- [Saving and Loading](#saving-and-loading)
- [Technical Highlights](#technical-highlights)
- [Contributing](#contributing)
- [License](#license)

---

## Features

- Play against another player or AI with **3 difficulty levels**:
  - Easy
  - Normal
  - Hard
- **Customization** of game symbols and colors for a personalized experience.
- **Save and Load** functionality to resume your game anytime.
- **AI Implementation** designed to provide challenging gameplay at different skill levels.
- Fully functional **command-line interface** for intuitive interaction.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/YoussefSelk/Morpion.git
   cd Morpion
2. Compile the game using `gcc` or another C compiler:
   ```bash
   gcc -o morpion morpion.c
   ./morpion
## Usage

1. After starting the game, choose between playing:
   - Player vs. Player
   - Player vs. AI (select a difficulty level)

2. Customize your game symbols and colors if desired.

3. Play the game by entering the row and column numbers to place your symbol.

4. Save your progress anytime during gameplay or load a previously saved game.

---

## Game Modes

### Player vs. Player
Two human players take turns placing their symbols on a 3x3 grid. The first to align three symbols horizontally, vertically, or diagonally wins the game.

### Player vs. AI
Challenge the computer with adjustable difficulty levels:
- **Easy**: The AI makes random moves.
- **Normal**: The AI implements basic strategies.
- **Hard**: The AI uses advanced strategies to maximize its chances of winning.

---

## Customization

Before starting the game, players can:
- Choose their symbols for "X" and "O".
- Select colors for their symbols, enhancing the game's visual experience.

---

## Saving and Loading

- **Save**: Players can save their progress during the game and continue later.
- **Load**: Resume a saved game from the exact point it was left off.

---

## Technical Highlights

This project was an opportunity to explore and apply various programming concepts, including:

- **Game State Management**: Efficiently maintaining and updating the state of the game.
- **AI Implementation**: Developing algorithms for AI gameplay at different difficulty levels.
- **Dynamic Memory Allocation**: Managing memory effectively for saving/loading game states.
- **User Interaction**: Building an intuitive command-line interface for smooth user interaction.

---

## Contributing

Contributions are welcome! Follow these steps to contribute:

1. Fork the repository:
   ```bash
   git fork https://github.com/YoussefSelk/Morpion.git

2. Clone your fork:
   ```bash
   git clone https://github.com/<your-username>/Morpion.git
   cd Morpion

3. Create a new branch:
   ```bash
   git checkout -b feature-name
   
4. Commit your changes:
   ```bash
   git commit -m "Add a new feature"
   
5. Push to the branch:
   ```bash
   git push origin feature-name


## License

This project is licensed under the [MIT License](LICENSE).  
Feel free to use, modify, and distribute this project as per the license terms.




