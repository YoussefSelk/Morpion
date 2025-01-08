#include "player.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
//#define RED "\033[1;31m"
//#define BLUE "\033[1;34m"
//#define RESET "\033[0m"

PlayerStats player1Stats = {0, 0, 0};
PlayerStats player2Stats = {0, 0, 0};

//extern char grid[3][3];  
//int computerDifficulty = 1;  

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
    grid[row][col] = 'O'; 
}


void computerMoveNormal() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') {
                grid[i][j] = 'X';  
                if (checkWinner()) {
                    grid[i][j] = 'O';  
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
                    grid[i][j] = 'O'; 
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

    if (canWinOrBlock('O')) return; 
    if (canWinOrBlock('X')) return; 

    
    if (grid[0][0] == ' ') { grid[0][0] = 'O'; return; }
    if (grid[0][2] == ' ') { grid[0][2] = 'O'; return; }
    if (grid[2][0] == ' ') { grid[2][0] = 'O'; return; }
    if (grid[2][2] == ' ') { grid[2][2] = 'O'; return; }

    
    if (grid[1][1] == ' ') { grid[1][1] = 'O'; return; }

    
    if (grid[0][1] == ' ') { grid[0][1] = 'O'; return; }
    if (grid[1][0] == ' ') { grid[1][0] = 'O'; return; }
    if (grid[1][2] == ' ') { grid[1][2] = 'O'; return; }
    if (grid[2][1] == ' ') { grid[2][1] = 'O'; return; }

    
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
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void playerMove(int player) {
    int row, col;
    char command;  
    const char* playerColor = (player == 1) ? RED : BLUE;

    while (1) {
        printf("%sJoueur %d%s, entrez votre mouvement (ligne colonne), ou 'p' pour pauser : ", playerColor, player, RESET);

        
        scanf(" %c", &command);
        if (command == 'p' || command == 'P') {
            pauseMenu();  
            continue;  
        }

        if (isdigit(command)) {
            ungetc(command, stdin);  
            if (scanf("%d %d", &row, &col) == 2) {
                if (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') {
                    grid[row][col] = (player == 1) ? 'X' : 'O'; 
                    gameModified = 1;
                    break; 
                }
            }
        }

        
        printf(RED "Entrée invalide. Les coordonnées doivent être entre 0 et 2 et la case non occupée. Réessayez : " RESET); 
        clearInputBuffer();  
    }
}




//void playerMove(int player) {
//    int row, col;
//    
//    // Set player color based on symbol (Player 1: X -> RED, Player 2: O -> BLUE)
//    const char* playerColor = (player == 1) ? RED : BLUE;
//
//    // Print the prompt message with the player's color
//    printf("%sJoueur %d %s, entrez votre mouvement (ligne colonne, entre 0 et 2) : ", playerColor, player, RESET);
//    scanf("%d %d", &row, &col);
//    
//    // Loop until a valid move is provided
//    while (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != ' ') {
//        if (row < 0 || row > 2 || col < 0 || col > 2) {
//            printf(RED "Les coordonnees doivent etre entre 0 et 2. Reessayez : " RESET);
//        } else if (grid[row][col] != ' ') {
//            printf(RED "Case deja occupee. Reessayez : " RESET);
//        }
//        scanf("%d %d", &row, &col);
//    }
//    
//    // Set the symbol in the grid according to the player
//    grid[row][col] = (player == 1) ? 'X' : 'O';
//}

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
    // Print a header with a border
    printf(LINE BOLD "\n+-----------------------------------+\n" RESET);
    printf(LINE BOLD "|          Statistiques             |\n" RESET);
    printf(LINE BOLD "+-----------------------------------+\n" RESET);
    
    // Display stats for Player 1
    printf(GREEN BOLD "Joueur 1:\n" RESET);
    printf(CYAN "Victoires : " YELLOW "%d\n" RESET, player1Stats.gamesWon);
    printf(CYAN "Défaites  : " YELLOW "%d\n" RESET, player1Stats.gamesLost);
    printf(CYAN "Matchs Nuls: " YELLOW "%d\n" RESET, player1Stats.gamesDrawn);
    
    // Print a separating line
    printf(LINE "-------------------------------------\n" RESET);
    
    // Display stats for Player 2
    printf(GREEN BOLD "Joueur 2:\n" RESET);
    printf(CYAN "Victoires : " YELLOW "%d\n" RESET, player2Stats.gamesWon);
    printf(CYAN "Défaites  : " YELLOW "%d\n" RESET, player2Stats.gamesLost);
    printf(CYAN "Matchs Nuls: " YELLOW "%d\n" RESET, player2Stats.gamesDrawn);
    
    // Print a footer with a border
    printf(LINE "+-----------------------------------+\n" RESET);
    displayReturnToMainMenu();
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
    printf("Statistiques chargées.\n");
}

