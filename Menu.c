#include <stdio.h>
#include "menu.h"
#include "game.h"
#include "player.h"
#include "help.h"
#include "save.h"
#include "display.h"
#include "globals.h"


void displayMenu() {
	if(!game_finished){
		clearConsole();
	}else{
		game_finished = 0;
	}
	
    printf(BOLD LINE "\n+------------------------+\n" RESET);
    printf(BOLD LINE "|       JEU MORPION      |\n" RESET);
    printf(BOLD LINE "+------------------------+\n" RESET);

    printf("1. " NUM "Nouvelle Partie (2 Joueurs)\n" RESET);
    printf("2. " NUM "Nouvelle Partie (Joueur vs IA)\n" RESET);
    printf("3. " NUM "Charger une Partie\n" RESET);
    printf("4. " NUM "Sauvegarder la Partie\n" RESET);
    printf("5. " NUM "Aide\n" RESET);
    printf("6. " NUM "Statistiques\n" RESET); // Nouvelle option pour les statistiques
    printf("7. " NUM "Personalisation\n" RESET);
    printf("8. " RED "Quitter\n" RESET);
    printf("Choix : ");
}

void displayReturnToMainMenu() {
    char choice;
    do {
        printf(BOLD "\nAppuyez sur 'm' pour retourner au Menu Principal..." RESET);
        scanf(" %c", &choice);  // Lire un caract�re
        while (getchar() != '\n');  // Nettoyage du buffer pour �viter des entr�es fant�mes
    } while (choice != 'm' && choice != 'M');  // Boucle jusqu'� ce que 'm' ou 'M' soit entr�
	runMainMenuLoop();
}
int chooseDifficulty() {
    int difficulty;
    int status;
    do {
    	clearConsole();
        printf("\nChoisissez la difficult� pour l'ordinateur :\n");
        printf("1. Easy\n");
        printf("2. Normal\n");
        printf("3. Hard\n");
        printf("Choix : ");
        status = scanf("%d", &difficulty);

        // V�rifie si l'entr�e est valide
        if (status != 1) {
            printf("Entr�e invalide. Veuillez entrer un nombre.\n");
            // Vider le buffer d'entr�e pour supprimer les donn�es non d�sir�es
            while (getchar() != '\n');
        } else if (difficulty < 1 || difficulty > 3) {
            printf("Veuillez choisir un num�ro entre 1 et 3.\n");
            status = 0; // Assurez-vous de rester dans la boucle si le num�ro n'est pas valide
        }

    } while (status != 1); // Continue tant que l'entr�e n'est pas un entier valide

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
            displayCustomizationMenu();
            break;
        case 8:
            exitGame(); // Quitter le jeu
            break;
        default:
            printf("Choix invalide, veuillez r�essayer.\n");
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
            	loading = 1;
            	if (gameModified) {
			        printf("\033[0;33mVoulez-vous sauvegarder avant de quitter ? (O/N) :\033[0m ");
			        scanf(" %c", &response);
			
			        if (response == 'O' || response == 'o') {
			            saveGame(); 
			            printf("\033[0;32mPartie sauvegard�e. Merci d'avoir jou� !\033[0m\n");
			        } else {
			            printf("\033[0;32mMerci d'avoir jou� !\033[0m\n");
			        }
			    } else {
			        printf("\033[0;32mAucun changement � sauvegarder. Merci d'avoir jou� !\033[0m\n");
			    }
			    ingame = 0;
                runMainMenuLoop();
                break;
            case '4':
            	
                exitGame();
                break;    
            default:
                printf("\nChoix invalide, r�essayez.\n");
        }
    } while (choice != '1'); 

  
    displayGrid(grid);
}
void displayReturnToGame() {
    char choice;
	
    do {
        printf("\n=== Menu ===\n");
        printf("1. Retourner au menu de pause\n");
        printf("2. Quitter la Partie (Menu Principal)\n");
        printf("3. Quitter le Jeu\n");
        printf("Faites votre choix : ");
        scanf(" %c", &choice);
		char response;
        switch (choice) {
            case '1':
            	clearConsole();
                break;
            case '2':
            	loading = 1;
            	if (gameModified) {
			        printf("\033[0;33mVoulez-vous sauvegarder avant de quitter ? (O/N) :\033[0m ");
			        scanf(" %c", &response);
			
			        if (response == 'O' || response == 'o') {
			            saveGame(); 
			            printf("\033[0;32mPartie sauvegard�e. Merci d'avoir jou� !\033[0m\n");
			        } else {
			            printf("\033[0;32mMerci d'avoir jou� !\033[0m\n");
			        }
			    } else {
			        printf("\033[0;32mAucun changement � sauvegarder. Merci d'avoir jou� !\033[0m\n");
			    }
			    ingame = 0;
                runMainMenuLoop();
                break;
            case '3':
                exitGame();
                break;    
            default:
                printf("\nChoix invalide, r�essayez.\n");
        }
    } while (choice != '1'); 

}
void runMainMenuLoop() {
    loadStats();  // Charger les statistiques avant de d�marrer la boucle du menu
    loadCustomizations_colors();
    loadCustomizations_symbols();
    int choix;
    do {
        displayMenu();  // Afficher les options du menu
        scanf("%d", &choix);
        while (getchar() != '\n');  // Nettoyer le buffer d'entr�e pour �viter les entr�es en exc�s
        handleMenuChoice(choix);  // G�rer le choix de l'utilisateur
    } while (choix != 8);  // Continuer jusqu'� ce que l'utilisateur choisisse de quitter
}
