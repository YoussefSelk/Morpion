#include "save.h"
#include "game.h"
#include <stdio.h>

extern char grid[3][3];  // Utiliser la grille globale
extern int currentPlayer;

void saveGame() {
    if (!gameModified) {
        printf("Aucun changement depuis le dernier état sauvegardé. Sauvegarde non nécessaire.\n");
        return;
    }

    FILE *file = fopen("savegame.txt", "w");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
        return;
    }
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
    printf("Jeu sauvegardé !\n");
    gameModified = 0;  // Réinitialiser après la sauvegarde
}


void loadGame() {
    FILE *file = fopen("savegame.txt", "r");
    if (file == NULL) {
        printf("Erreur lors du chargement : Le fichier n'existe peut-être pas.\n");
        return;
    }

    int error = 0;
    char temp;
	int i,j;

    for (i = 0; i < 3 && !error; i++) {
        for (j = 0; j < 3; j++) {
            if (fscanf(file, " %c", &temp) != 1) {
                error = 1;
                break;
            }
            grid[i][j] = temp == '-' ? ' ' : temp;  // Convertir les tirets en espaces
        }
    }

    if (!error && fscanf(file, "%d", &currentPlayer) != 1) {
        error = 1;
    }

    fclose(file);

    if (error) {
        printf("Erreur lors du chargement : Le fichier est corrompu ou mal formé.\n");
    } else {
        printf("Jeu chargé avec succès !\n");
        gameModified = 0;
    }
}
