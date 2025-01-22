#include "save.h"
#include "game.h"
#include "globals.h"
#include <stdio.h>

extern char grid[3][3];  
extern int currentPlayer;
extern int checkWinner();  
extern void displayGrid(char grid[3][3]);


int selectSaveSlot() {
    int slot;
    printf("Choisissez un slot de sauvegarde (1-3): ");
    scanf("%d", &slot);
    while (slot < 1 || slot > 3) {
        printf("Entree invalide. Veuillez choisir un numero entre 1 et 3: ");
        scanf("%d", &slot);
    }
    return slot;
}
void saveGame() {
    if (!gameModified) {
        printf("Aucun changement depuis le dernier etat sauvegarde. Sauvegarde non necessaire.\n");
        return;
    }

    int slot = selectSaveSlot();
    char filename[20];
    sprintf(filename, "savegame%d.txt", slot);  

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
        return;
    }
    fprintf(file, "%d\n", gameMode);
	int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            char ch = (grid[i][j] == ' ') ? '-' : grid[i][j];
            fprintf(file, "%c ", ch);
        }
        fprintf(file, "\n");
    }

    fprintf(file, "%d", currentPlayer);
    fclose(file);
    printf("Jeu sauvegarde dans le slot %d !\n", slot);
    gameModified = 0;
}
void loadGame() {
    int slot = selectSaveSlot();
    char filename[20];
    char temp;  // D�claration de la variable temp pour stocker les caract�res lus
    sprintf(filename, "savegame%d.txt", slot);  // Construire le nom du fichier bas� sur le slot choisi

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur lors du chargement : Le fichier pour le slot %d n'existe peut-etre pas.\n", slot);
        return;
    }

    int error = 0;
    if (fscanf(file, "%d", &gameMode) != 1) {
        error = 1;
    }
	int i,j;
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
        printf("Erreur lors du chargement : Le fichier est corrompu ou mal forme.\n");
    } else {
        printf("Jeu charge du slot %d avec succes !\n", slot);
        gameModified = 0;
        displayGrid(grid);
        int result = checkWinner();
        if (result != 0) {
            printf("La partie est deja terminee.\n");
            game_finished = 1;
        } else {
            playGame();
        }
    }
}








//
//void saveGame() {
//    if (!gameModified) {
//        printf("Aucun changement depuis le dernier �tat sauvegard�. Sauvegarde non n�cessaire.\n");
//        return;
//    }
//
//    FILE *file = fopen("savegame.txt", "w");
//    if (file == NULL) {
//        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
//        return;
//    }
//    fprintf(file, "%d\n", gameMode);
//
//	int i , j;
//    for (i = 0; i < 3; i++) {
//        for (j = 0; j < 3; j++) {
//            char ch = (grid[i][j] == ' ') ? '-' : grid[i][j];
//            fprintf(file, "%c ", ch);
//        }
//        fprintf(file, "\n");
//    }
//
//    fprintf(file, "%d", currentPlayer);
//    fclose(file);
//    printf("Jeu sauvegard� !\n");
//    gameModified = 0; 
//}
//void loadGame() {
//    FILE *file = fopen("savegame.txt", "r");
//    if (file == NULL) {
//        printf("Erreur lors du chargement : Le fichier n'existe peut-�tre pas.\n");
//        return;
//    }
//
//    int error = 0;
//    char temp;
//    int i, j;
//
//    
//    if (fscanf(file, "%d", &gameMode) != 1) {
//        error = 1;
//    }
//
//    for (i = 0; i < 3 && !error; i++) {
//        for (j = 0; j < 3; j++) {
//            if (fscanf(file, " %c", &temp) != 1) {
//                error = 1;
//                break;
//            }
//            grid[i][j] = temp == '-' ? ' ' : temp;  
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
//
//        
//        displayGrid(grid);
//
//        
//        int result = checkWinner();
//        if (result != 0) {
//            if (result == 3) {
//                printf("La partie est un match nul.\n");
//            } else {
//                printf("Le joueur %d a gagn�!\n", result);
//            }
//        } else {
//            playGame();
//        }
//    }
//}

