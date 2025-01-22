#include "display.h"
#include "globals.h"  
#include <stdio.h>
#include <stdlib.h>

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayGrid(char grid[3][3]) {
    clearConsole();

    printf("\n");
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == player1Symbol) {
                printf(" %s%c%s ", player1Color, grid[i][j], RESET);  
            } else if (grid[i][j] == player2Symbol) {
                printf(" %s%c%s ", player2Color, grid[i][j], RESET);  
            } else {
                printf("   ");
            }
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---+---+---\n");
    }
    printf("\n");
}

