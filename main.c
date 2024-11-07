#include <stdio.h>
#include "game.h"
#include "player.h"
#include "help.h"
#include "save.h"
#include "display.h"

void displayMenu() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Nouvelle Partie (2 Joueurs)\n");
    printf("2. Nouvelle Partie (Joueur vs Ordinateur)\n");
    printf("3. Charger une Partie\n");
    printf("4. Sauvegarder la Partie\n");  // Nouvelle option pour sauvegarder la partie
    printf("5. Aide\n");
    printf("6. Quitter\n");
    printf("Choix : ");
}

int chooseDifficulty() {
    int difficulty;
    printf("\nChoisissez la difficulté pour l'ordinateur :\n");
    printf("1. Easy\n");
    printf("2. Normal\n");
    printf("3. Hard\n");
    printf("Choix : ");
    scanf("%d", &difficulty);
    return difficulty;
}

int main() {
    int choix;
    do {
        displayMenu();
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                initGame(2);  // Partie entre 2 joueurs
                playGame();
                break;
            case 2:
                initGame(1);  // Partie contre l'ordinateur
                setDifficulty(chooseDifficulty());  // Appliquer la difficulté choisie
                playGame();
                break;
            case 3:
                loadGame();  // Charger la partie depuis le fichier de sauvegarde
                playGame();  // Reprendre la partie
                break;
            case 4:
                saveGame();  // Sauvegarder la partie
                break;
            case 5:
                displayHelp();  // Afficher l'aide
                break;
            case 6:
                printf("Merci d'avoir joué !\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 6);
    return 0;
}

