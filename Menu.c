#include <stdio.h>
#include "menu.h"
#include "game.h"
#include "player.h"
#include "help.h"
#include "save.h"
#include "display.h"

#define RED "\033[1;31m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define LINE "\033[1;34m" 
#define NUM "\033[1;32m"  


extern char grid[3][3];



void displayMenu() {
	clearConsole();
    printf(BOLD LINE "\n+------------------------+\n" RESET);
    printf(BOLD LINE "|       JEU MORPION      |\n" RESET);
    printf(BOLD LINE "+------------------------+\n" RESET);

    printf("1. " NUM "Nouvelle Partie (2 Joueurs)\n" RESET);
    printf("2. " NUM "Nouvelle Partie (Joueur vs IA)\n" RESET);
    printf("3. " NUM "Charger une Partie\n" RESET);
    printf("4. " NUM "Sauvegarder la Partie\n" RESET);
    printf("5. " NUM "Aide\n" RESET);
    printf("6. " NUM "Statistiques\n" RESET); // Nouvelle option pour les statistiques
    printf("7. " RED "Quitter\n" RESET);
    printf("Choix : ");
}

void displayReturnToMainMenu() {
    char choice;
    do {
        printf(BOLD "\nAppuyez sur 'm' pour retourner au Menu Principal..." RESET);
        scanf(" %c", &choice);  // Lire un caractère
        while (getchar() != '\n');  // Nettoyage du buffer pour éviter des entrées fantômes
    } while (choice != 'm' && choice != 'M');  // Boucle jusqu'à ce que 'm' ou 'M' soit entré
	runMainMenuLoop();
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

void handleMenuChoice(int choice) {
    switch(choice) {
        case 1:
            initGame(2);  
            playGame();
            break;
        case 2:
            initGame(1);  
            setDifficulty(chooseDifficulty());  
            playGame();
            break;
        case 3:
            loadGame();  
            break;
        case 4:
            saveGame();  
            break;
        case 5:
            displayHelp();  
            break;
        case 6:
            displayStats(); // Afficher les statistiques des joueurs
            break;
        case 7:
            exitGame(); // Quitter le jeu
            break;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
    }
}

void pauseMenu() {
    char choice;

    clearConsole();

    do {
        printf("\n=== Menu de Pause ===\n");
        printf("1. Continuer le jeu\n");
        printf("2. Afficher les statistiques des joueurs\n");
        printf("3. Quitter la Partie (Menu Principal)\n");
        printf("4. Quitter le Jeu\n");
        printf("Faites votre choix : ");
        scanf(" %c", &choice);
		char response;
        switch (choice) {
            case '1':
                printf("\nReprise du jeu...\n");
                break;
            case '2':
                 
                displayStats();
                break;
            case '3':
            	
            	if (gameModified) {
			        printf("\033[0;33mVoulez-vous sauvegarder avant de quitter ? (O/N) :\033[0m ");
			        scanf(" %c", &response);
			
			        if (response == 'O' || response == 'o') {
			            saveGame(); 
			            printf("\033[0;32mPartie sauvegardée. Merci d'avoir joué !\033[0m\n");
			        } else {
			            printf("\033[0;32mMerci d'avoir joué !\033[0m\n");
			        }
			    } else {
			        printf("\033[0;32mAucun changement à sauvegarder. Merci d'avoir joué !\033[0m\n");
			    }
                runMainMenuLoop();
                break;
            case '4':
                exitGame();
                break;    
            default:
                printf("\nChoix invalide, réessayez.\n");
        }
    } while (choice != '1'); 

  
    displayGrid(grid);
}
void runMainMenuLoop() {
    loadStats();  // Charger les statistiques avant de démarrer la boucle du menu
    int choix;
    do {
        displayMenu();  // Afficher les options du menu
        scanf("%d", &choix);
        while (getchar() != '\n');  // Nettoyer le buffer d'entrée pour éviter les entrées en excès
        handleMenuChoice(choix);  // Gérer le choix de l'utilisateur
    } while (choix != 7);  // Continuer jusqu'à ce que l'utilisateur choisisse de quitter
}
