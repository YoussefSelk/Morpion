#include "player.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

extern char grid[3][3];  // Utiliser la grille déclarée dans game.c
int computerDifficulty = 1;  // Par défaut, on commence avec "Easy"

// Définit la difficulté de l'ordinateur
void setDifficulty(int difficulty) {
    computerDifficulty = difficulty;
}

// Generates a random empty cell position
void getRandomEmptyCell(int *row, int *col) {
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (grid[*row][*col] != ' ');
}

void computerMoveEasy() {
    int row, col;
    getRandomEmptyCell(&row, &col);
    grid[row][col] = 'O'; // Computer plays 'O'
}


// IA "Normal" : essaie de bloquer les coups gagnants du joueur
void computerMoveNormal() {
    int i, j;
    // 1. Bloquer les coups gagnants du joueur
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                grid[i][j] = 'X';  // Simuler un coup du joueur
                if (checkWinner()) {
                    grid[i][j] = 'O';  // Bloquer le joueur
                    return;
                }
                grid[i][j] = ' ';  // Annuler le coup simulé
            }
        }
    }
    // 2. Jouer comme Easy s'il n'y a rien à bloquer
    computerMoveEasy();
}

int canWinOrBlock(char player) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                grid[i][j] = player;
                if (checkWinner()) {
                    grid[i][j] = 'O'; // If `player` is 'X', we block; if 'O', we win
                    return 1; // Return if win or block found
                }
                grid[i][j] = ' '; // Undo move
            }
        }
    }
    return 0; // No winning/blocking move found
}
void computerMoveHard() {
    int i, j;

    if (canWinOrBlock('O')) return; // Check for winning move first
    if (canWinOrBlock('X')) return; // Then block opponent's win

    // 3. Prioritize taking corners
    if (grid[0][0] == ' ') { grid[0][0] = 'O'; return; }
    if (grid[0][2] == ' ') { grid[0][2] = 'O'; return; }
    if (grid[2][0] == ' ') { grid[2][0] = 'O'; return; }
    if (grid[2][2] == ' ') { grid[2][2] = 'O'; return; }

    // 4. Take the center if available
    if (grid[1][1] == ' ') { grid[1][1] = 'O'; return; }

    // 5. Play on the sides if nothing else is available
    if (grid[0][1] == ' ') { grid[0][1] = 'O'; return; }
    if (grid[1][0] == ' ') { grid[1][0] = 'O'; return; }
    if (grid[1][2] == ' ') { grid[1][2] = 'O'; return; }
    if (grid[2][1] == ' ') { grid[2][1] = 'O'; return; }

    // If no other moves are possible, use the normal move function
    computerMoveNormal();
}



void computerMove() {
    if (computerDifficulty == 1) {
        computerMoveEasy();
    } else if (computerDifficulty == 2) {
        computerMoveNormal();
    } else {
        computerMoveHard();
    }
}

void playerMove (int player) {
    int row, col;
    printf("Joueur %d, entrez votre mouvement (ligne colonne) : ", player);
    scanf("%d %d", &row, &col);
    while (grid[row][col] != ' ') {
        printf("Case déjà occupée. Réessayez : ");
        scanf("%d %d", &row, &col);
    }
    grid[row][col] = (player == 1) ? 'X' : 'O';
}

