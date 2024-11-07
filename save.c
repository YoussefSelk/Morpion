#include "save.h"
#include <stdio.h>

extern char grid[3][3];  // Utiliser la grille globale
extern int currentPlayer;

void saveGame() {
    FILE *file = fopen("savegame.txt", "w");  // Ouvre le fichier en mode écriture
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde.\n");
        return;
    }
int i,j ;
    // Sauvegarder la grille de jeu ligne par ligne
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            fprintf(file, "%c ", grid[i][j]);  // Sauvegarde chaque case de la grille avec un espace
        }
        fprintf(file, "\n");  // Retour à la ligne pour chaque ligne de la grille
    }

    // Sauvegarder le joueur courant (1 ou 2)
    fprintf(file, "%d", currentPlayer);
    
    fclose(file);  // Ferme le fichier
    printf("Jeu sauvegardé !\n");
}

void loadGame() {
    FILE *file = fopen("savegame.txt", "r");  // Ouvre le fichier en mode lecture
    if (file == NULL) {
        printf("Erreur lors du chargement. Le fichier n'existe peut-être pas.\n");
        return;
    }
int i,j;
    // Charger la grille de jeu ligne par ligne
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            fscanf(file, " %c", &grid[i][j]);  // Lire chaque case de la grille et la stocker
        }
    }

    // Charger le joueur courant
    fscanf(file, "%d", &currentPlayer);  // Charger le joueur courant (1 ou 2)
    
    fclose(file);  // Ferme le fichier
    printf("Jeu chargé !\n");
}


