#include "help.h"
#include "display.h"
#include <stdio.h>

void displayHelp() {
	clearConsole();
    printf("\n=== Aide du Jeu Tic-Tac-Toe ===\n");
    printf("1. Deux joueurs s'affrontent pour placer leurs symboles ('X' ou 'O') sur une grille de 3x3.\n");
    printf("2. Le premier joueur qui aligne 3 symboles (horizontalement, verticalement ou en diagonale) gagne.\n");
    printf("3. Si toutes les cases sont remplies sans gagnant, c'est un match nul.\n");
    printf("4. Vous pouvez sauvegarder ou charger une partie en cours.\n");
    printf("Bonne chance et amusez-vous bien !\n\n");

    displayReturnToMainMenu();  
}

