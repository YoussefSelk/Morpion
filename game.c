#include "game.h"
#include "menu.h"
#include "display.h"
#include "player.h"
#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"


void initGame(int mode){
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] = ' ';  
    currentPlayer = 1;  
    gameMode = mode;
    gameModified = 0;
}

void playGame() {
	ingame = 1;
    int moves = 0;
    int winner = 0; 
    displayGrid(grid); 

    while (moves < 9 && winner == 0) {
        if (gameMode == 1 && currentPlayer == 2) {
            computerMove(); 
        } else {
            playerMove(currentPlayer);
        }
        moves++;
        displayGrid(grid); 
        winner = checkWinner();
        if (winner == 0 && moves < 9) {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }

    if (winner != 0) {
    	ingame = 0;
    	game_finished = 1;
        printf("Le joueur %d a gagne !\n", currentPlayer); 
        updateStats(currentPlayer); 
        saveStats(); 
		
    } else {
    	ingame = 0;
    	game_finished = 1;
        printf("Match nul !\n"); 
        updateStats(0); 
    }
    gameModified = 1;
}

int checkWinner() {
    int i;
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

void exitGame() {
    char response;

    if (gameModified) {
        printf("\033[0;33mVoulez-vous sauvegarder avant de quitter ? (O/N) :\033[0m ");
        scanf(" %c", &response);

        if (response == 'O' || response == 'o') {
            saveGame(); 
            printf("\033[0;32mPartie sauvegardee. Merci d'avoir joue !\033[0m\n");
        } else {
            printf("\033[0;32mMerci d'avoir joue !\033[0m\n");
        }
    } else {
        printf("\033[0;32mAucun changement à sauvegarder. Merci d'avoir joue !\033[0m\n");
    }
	ingame = 0;
    exit(0);
}

void pauseGame() {
    printf("\033[0;36mJeu en pause. Appuyez sur 'p' suivie de 'Entree' pour continuer...\033[0m\n");
    char c;
    do {
        scanf(" %c", &c);  
    } while (c != 'p');
}

