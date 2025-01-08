#include "display.h"
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
    int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == 'X') {
                printf(" \033[0;31mX\033[0m ");  
            } else if (grid[i][j] == 'O') {
                printf(" \033[0;34mO\033[0m ");  
            } else {
                printf("   ");  
            }
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---+---+---\n"); 
    }
    printf("\n");
}


