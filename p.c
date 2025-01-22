#include "globals.h"
#include "display.h"
#include <stdio.h>


void setPlayerSymbol(int player) {
    char symbol;
    printf("Entrez le nouveau symbole pour le Joueur %d: ", player);
    scanf(" %c", &symbol); 

    if (player == 1) {
        player1Symbol = symbol;
    } else {
        player2Symbol = symbol;
    }
}

void setPlayerColor(int player) {
    int colorChoice;
    printf("Choisissez la couleur pour le Joueur %d:\n", player);
    printf("1. Rouge\n2. Bleu\n3. Vert\n4. Jaune\nChoix: ");
    scanf("%d", &colorChoice);

    const char* colorCode = "";
    switch (colorChoice) {
        case 1:
            colorCode = "\033[0;31m"; // Red
            break;
        case 2:
            colorCode = "\033[0;34m"; // Blue
            break;
        case 3:
            colorCode = "\033[0;32m"; // Green
            break;
        case 4:
            colorCode = "\033[0;33m"; // Yellow
            break;
        default:
            printf("Couleur invalide. Rouge par defaut.\n");
            colorCode = "\033[0;31m"; // Default to Red
            break;
    }

    if (player == 1) {
        player1Color = colorCode;
    } else {
        player2Color = colorCode;
    }
}


void saveCustomizations_colors() {
    FILE *file = fopen("custom_colors.txt", "w"); 
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(file, "%s\n", player1Color);
    fprintf(file, "%s\n", player2Color);

    fclose(file); 
    printf("Personnalisations sauvegardées avec succès.\n");
}

void loadCustomizations_colors() {
    FILE *file = fopen("custom_colors.txt", "r");
    if (!file) {
        printf("Erreur : Fichier de personnalisation introuvable. Utilisation des couleurs par défaut.\n");
        player1Color = strdup("\033[1;31m"); // Rouge
        player2Color = strdup("\033[1;34m"); // Bleu
        return;
    }

    char buffer1[100], buffer2[100];
    if (fgets(buffer1, sizeof(buffer1), file)) {
        buffer1[strcspn(buffer1, "\n")] = 0;
        if (player1Color != NULL) free(player1Color);
        player1Color = strdup(buffer1);
    }

    if (fgets(buffer2, sizeof(buffer2), file)) {
        buffer2[strcspn(buffer2, "\n")] = 0;
        if (player2Color != NULL) free(player2Color);
        player2Color = strdup(buffer2);
    }

    fclose(file);
}

void saveCustomizations_symbols() {
    FILE *file = fopen("custom_symbols.txt", "w"); 
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(file, "%c\n", player1Symbol);
    fprintf(file, "%c\n", player2Symbol);

    fclose(file); 
    printf("Personnalisations des symboles sauvegardées avec succès.\n");
}

void loadCustomizations_symbols() {
    FILE *file = fopen("custom_symbols.txt", "r");
    if (!file) {
        printf("Erreur : Fichier de personnalisation des symboles introuvable. Utilisation des symboles par défaut.\n");
        player1Symbol = 'X'; 
        player2Symbol = 'O'; 
        return;
    }

    fscanf(file, " %c", &player1Symbol);
    fscanf(file, " %c", &player2Symbol);

    fclose(file);
}

void displayCustomizationMenu() {
    int choice;
    int stat = 1;
	do {
		if(stat){
			clearConsole();	
		}
        stat = 1;
        printf("\n=== Menu de Personnalisation ===\n");
        printf("1. Changer le symbole du Joueur 1\n");
        printf("2. Changer la couleur du Joueur 1\n");
        printf("3. Changer le symbole du Joueur 2\n");
        printf("4. Changer la couleur du Joueur 2\n");
        printf("5. Retourner au menu principal\n");
        printf("Faites votre choix (1-5) : ");
        
        if (scanf("%d", &choice) != 1) {
        	stat = 0;
            printf("Entree invalide, veuillez entrer un numero entre 1 et 5.\n");
            while(getchar() != '\n');  
            continue;
        }

        if (choice < 1 || choice > 5) {
        	stat = 0;
            printf("Choix invalide, veuillez entrer un numero entre 1 et 5.\n");
            continue;
        }

        switch (choice) {
            case 1:
                setPlayerSymbol(1);
                break;
            case 2:
                setPlayerColor(1);
                break;
            case 3:
                setPlayerSymbol(2);
                break;
            case 4:
                setPlayerColor(2);
                break;
            case 5:
                break;  
        }
    } while (choice != 5);

    saveCustomizations_colors(); 
	saveCustomizations_symbols();  
}



