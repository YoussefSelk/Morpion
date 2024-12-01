#include <stdio.h>
#include "menu.h"

int main() {
    int choix;
    do {
        displayMenu();
        scanf("%d", &choix);
        handleMenuChoice(choix);
    } while (choix != 6);
    return 0;
}

