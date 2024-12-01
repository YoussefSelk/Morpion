#ifndef GAME_H
#define GAME_H

extern int gameModified;

void initGame(int mode);  // mode = 1 pour joueur vs ordinateur, 2 pour 2 joueurs
void playGame();  // Fonction principale pour jouer
int checkWinner();  // Vérifie si un joueur a gagné
void exitGame();
#endif

