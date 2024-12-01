#include "game.h"
#include "display.h"
#include "player.h"
#include "save.h"
#include <stdio.h>
#include <stdlib.h>

char grid[3][3];  // Grille de jeu
int currentPlayer;  // Joueur courant (1 ou 2)
int gameMode;  // 1 pour joueur vs ordinateur, 2 pour 2 joueurs
int gameModified = 0; 


void initGame(int mode) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] = ' ';  // Initialiser la grille
    currentPlayer = 1;  // Joueur 1 commence
    gameMode = mode;
    gameModified = 0;
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
        printf("Le joueur %d a gagn� !\n", currentPlayer);
    } else {
        printf("Match nul !\n");
    }
    gameModified = 1;
}

int checkWinner() {
    int i;
    // V�rifie les lignes, colonnes et diagonales pour voir s'il y a un gagnant
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

// Fonction pour quitter le jeu avec demande de sauvegarde
void exitGame() {
    char response;

    // Afficher le message avec couleur uniquement si des modifications ont �t� effectu�es
    if (gameModified) {
        printf("\033[0;33mVoulez-vous sauvegarder avant de quitter ? (O/N) :\033[0m ");
        scanf(" %c", &response);

        // Gestion de la r�ponse avec prise en compte de la casse
        if (response == 'O' || response == 'o') {
            saveGame();  // Appel de la fonction saveGame pour sauvegarder la partie
            printf("\033[0;32mPartie sauvegard�e. Merci d'avoir jou� !\033[0m\n");
        } else {
            printf("\033[0;32mMerci d'avoir jou� !\033[0m\n");
        }
    } else {
        printf("\033[0;32mAucun changement � sauvegarder. Merci d'avoir jou� !\033[0m\n");
    }

    // Quitter le programme
    exit(0);
}

void pauseGame() {
    printf("\033[0;36mJeu en pause. Appuyez sur une touche pour continuer...\033[0m\n");
    getchar();  // Lire une touche pour continuer
    getchar();  // Utiliser deux fois si le tampon d'entr�e n'est pas vide
}

