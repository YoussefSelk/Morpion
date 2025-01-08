#include "save.h"
#include "game.h"
#include <stdio.h>

extern char grid[3][3];  
extern int currentPlayer;
extern int checkWinner();  
extern void displayGrid(char grid[3][3]);

void saveGame() {
    if (!gameModified) {
        printf("Aucun changement depuis le dernier �tat sauvegard�. Sauvegarde non n�cessaire.\n");
        return;
    }

    FILE *file = fopen("savegame.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
        return;
    }
    fprintf(file, "%d\n", gameMode);

	int i , j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            char ch = (grid[i][j] == ' ') ? '-' : grid[i][j];
            fprintf(file, "%c ", ch);
        }
        fprintf(file, "\n");
    }

    fprintf(file, "%d", currentPlayer);
    fclose(file);
    printf("Jeu sauvegard� !\n");
    gameModified = 0; 
}
void loadGame() {
    FILE *file = fopen("savegame.txt", "r");
    if (file == NULL) {
        printf("Erreur lors du chargement : Le fichier n'existe peut-�tre pas.\n");
        return;
    }

    int error = 0;
    char temp;
    int i, j;

    
    if (fscanf(file, "%d", &gameMode) != 1) {
        error = 1;
    }

    for (i = 0; i < 3 && !error; i++) {
        for (j = 0; j < 3; j++) {
            if (fscanf(file, " %c", &temp) != 1) {
                error = 1;
                break;
            }
            grid[i][j] = temp == '-' ? ' ' : temp;  
        }
    }

    if (!error && fscanf(file, "%d", &currentPlayer) != 1) {
        error = 1;
    }

    fclose(file);

    if (error) {
        printf("Erreur lors du chargement : Le fichier est corrompu ou mal form�.\n");
    } else {
        printf("Jeu charg� avec succ�s !\n");
        gameModified = 0;

        
        displayGrid(grid);

        
        int result = checkWinner();
        if (result != 0) {
            if (result == 3) {
                printf("La partie est un match nul.\n");
            } else {
                printf("Le joueur %d a gagn�!\n", result);
            }
        } else {
            playGame();
        }
    }
}
//void loadGame() {
//    FILE *file = fopen("savegame.txt", "r");
//    if (file == NULL) {
//        printf("Erreur lors du chargement : Le fichier n'existe peut-�tre pas.\n");
//        return;
//    }
//
//    int error = 0;
//    char temp;
//	int i,j;
//
//    for (i = 0; i < 3 && !error; i++) {
//        for (j = 0; j < 3; j++) {
//            if (fscanf(file, " %c", &temp) != 1) {
//                error = 1;
//                break;
//            }
//            grid[i][j] = temp == '-' ? ' ' : temp;  // Convertir les tirets en espaces
//        }
//    }
//
//    if (!error && fscanf(file, "%d", &currentPlayer) != 1) {
//        error = 1;
//    }
//
//    fclose(file);
//
//    if (error) {
//        printf("Erreur lors du chargement : Le fichier est corrompu ou mal form�.\n");
//    } else {
//        printf("Jeu charg� avec succ�s !\n");
//        gameModified = 0;
//    }
//}
