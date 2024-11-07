#include "game.h"
#include "display.h"
#include "player.h"
#include "save.h"
#include <stdio.h>

char grid[3][3];  // Grille de jeu
int currentPlayer;  // Joueur courant (1 ou 2)
int gameMode;  // 1 pour joueur vs ordinateur, 2 pour 2 joueurs



void initGame(int mode) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] = ' ';  // Initialiser la grille
    currentPlayer = 1;  // Joueur 1 commence
    gameMode = mode;
}

void playGame() {
    int moves = 0;
    while (moves < 9 && !checkWinner()) {
        displayGrid(grid);  // Afficher la grille avec couleurs et nettoyage
        if (gameMode == 1 && currentPlayer == 2) {
            computerMove();  // Tour de l'ordinateur
        } else {
            playerMove(currentPlayer);  // Tour du joueur
        }
        moves++;
        if (!checkWinner()) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;  // Changer de joueur
        }
    }
    displayGrid(grid);  // Afficher la grille finale
    if (checkWinner()) {
        printf("Le joueur %d a gagné !\n", currentPlayer);
    } else {
        printf("Match nul !\n");
    }
}

int checkWinner() {
    int i;
    // Vérifie les lignes, colonnes et diagonales pour voir s'il y a un gagnant
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ')
            return 1;
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ')
            return 1;
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ')
        return 1;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ')
        return 1;
    return 0;
}

