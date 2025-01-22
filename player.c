#include "player.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

PlayerStats player1Stats = {0, 0, 0};
PlayerStats player2Stats = {0, 0, 0};
 

void setDifficulty(int difficulty) {
    computerDifficulty = difficulty;
}

void getRandomEmptyCell(int *row, int *col) {
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (grid[*row][*col] != ' ');
}

void computerMoveEasy() {
    int row, col;
    getRandomEmptyCell(&row, &col);
   
  grid[row][col] = player2Symbol;
}


void computerMoveNormal() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                grid[i][j] = player1Symbol;  
                if (checkWinner()) { 
					grid[i][j] = player2Symbol;
                    return;
                }
                grid[i][j] = ' '; 
            }
        }
    }
    
    computerMoveEasy();
}

int canWinOrBlock(char player) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                grid[i][j] = player;
                if (checkWinner()) { 
                    grid[i][j] = player2Symbol;
                    return 1;
                }
                grid[i][j] = ' '; 
            }
        }
    }
    return 0;
}
void computerMoveHard() {
    int i, j;

	if (canWinOrBlock(player2Symbol)) return; 
    if (canWinOrBlock(player1Symbol)) return; 
    
	if (grid[0][0] == ' ') { grid[0][0] = player2Symbol; return; }
	if (grid[0][2] == ' ') { grid[0][2] = player2Symbol; return; }
	if (grid[2][0] == ' ') { grid[2][0] = player2Symbol; return; }
	if (grid[2][2] == ' ') { grid[2][2] = player2Symbol; return; }
	    
	if (grid[1][1] == ' ') { grid[1][1] = player2Symbol; return; }

    if (grid[0][1] == ' ') { grid[0][1] = player2Symbol; return; }
    if (grid[1][0] == ' ') { grid[1][0] = player2Symbol; return; }
    if (grid[1][2] == ' ') { grid[1][2] = player2Symbol; return; }
    if (grid[2][1] == ' ') { grid[2][1] = player2Symbol; return; }

    
    computerMoveNormal();
}


void sleep_ms(int milliseconds) {
    #ifdef _WIN32
    Sleep(milliseconds);  
    #else
    usleep(milliseconds * 1000);  
    #endif
}

void displayThinkingAnimation() {
    
    printf("\nL'ordinateur reflechit ");
    int i;
    for (i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout); 
        sleep_ms(500);  
    }
    printf("\n");
}

void computerMove() {
    displayThinkingAnimation();  

    if (computerDifficulty == 1) {
        computerMoveEasy();
    } else if (computerDifficulty == 2) {
        computerMoveNormal();
    } else {
        computerMoveHard();
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void playerMove(int player) {
    int index, row, col;
    char command;
    const char* playerColor = (player == 1) ? player1Color : player2Color;

    while (1) {
    	printf("\n");
        printf("%sJoueur %d%s, entrez votre mouvement (1-9), ou 'p' pour pauser : ", playerColor, player, RESET);

        if (scanf(" %c", &command) == 1) {
            if (command == 'p' || command == 'P') {
                pauseMenu();
                continue;
            }

            if (isdigit(command) && command >= '1' && command <= '9') {
            	
                index = command - '1';  // Convertir le caractère en index (0-8)
                row = 2 - (index / 3);  // Calculer la ligne (bas en haut)
                col = index % 3;        // Calculer la colonne (gauche à droite)

                if (grid[row][col] == ' ') {
                    grid[row][col] = (player == 1) ? player1Symbol : player2Symbol;
                    gameModified = 1;
                    break;
                } else {
                	printf("\n");
                    printf(RED "\nCase deja occupee. Reessayez : " RESET);
                    printf("\n");
                }
            } else {
            	printf("\n");
                printf(RED "Entree invalide. Saisissez un chiffre entre 1 et 9. Reessayez : " RESET);
                printf("\n");
            }
        }
        clearInputBuffer(); 
    }
}

void updateStats(int winner) {
    if (winner == 1) {
        player1Stats.gamesWon++;
        player2Stats.gamesLost++;
    } else if (winner == 2) {
        player2Stats.gamesWon++;
        player1Stats.gamesLost++;
    } else {
        player1Stats.gamesDrawn++;
        player2Stats.gamesDrawn++;
    }
    saveStats();
}

void displayStats() {
	clearConsole();
    printf(LINE BOLD "\n+-----------------------------------+\n" RESET);
    printf(LINE BOLD "|          Statistiques             |\n" RESET);
    printf(LINE BOLD "+-----------------------------------+\n" RESET);
    
    printf(GREEN BOLD "Joueur 1:\n" RESET);
    printf(CYAN "Victoires : " YELLOW "%d\n" RESET, player1Stats.gamesWon);
    printf(CYAN "Defaites  : " YELLOW "%d\n" RESET, player1Stats.gamesLost);
    printf(CYAN "Matchs Nuls: " YELLOW "%d\n" RESET, player1Stats.gamesDrawn);
    
    printf(LINE "-------------------------------------\n" RESET);
    
    printf(GREEN BOLD "Joueur 2:\n" RESET);
    printf(CYAN "Victoires : " YELLOW "%d\n" RESET, player2Stats.gamesWon);
    printf(CYAN "Defaites  : " YELLOW "%d\n" RESET, player2Stats.gamesLost);
    printf(CYAN "Matchs Nuls: " YELLOW "%d\n" RESET, player2Stats.gamesDrawn);
    
    printf(LINE "+-----------------------------------+\n" RESET);
    if(ingame){
    	displayReturnToGame();
	}else{
		displayReturnToMainMenu();
	}
    
}

void saveStats() {
    FILE *file = fopen("player_stats.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde des statistiques.\n");
        return;
    }
    fprintf(file, "%d %d %d\n", player1Stats.gamesWon, player1Stats.gamesLost, player1Stats.gamesDrawn);
    fprintf(file, "%d %d %d\n", player2Stats.gamesWon, player2Stats.gamesLost, player2Stats.gamesDrawn);
    fclose(file);
    printf("Statistiques sauvegardées.\n");
}

void loadStats() {
    FILE *file = fopen("player_stats.txt", "r");
    if (file == NULL) {
        printf("Erreur lors du chargement des statistiques : Le fichier n'existe peut-être pas.\n");
        return;
    }
    fscanf(file, "%d %d %d", &player1Stats.gamesWon, &player1Stats.gamesLost, &player1Stats.gamesDrawn);
    fscanf(file, "%d %d %d", &player2Stats.gamesWon, &player2Stats.gamesLost, &player2Stats.gamesDrawn);
    fclose(file);
}

