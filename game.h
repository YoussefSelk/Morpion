#ifndef GAME_H
#define GAME_H

void initGame(int mode);  // mode = 1 pour joueur vs ordinateur, 2 pour 2 joueurs
void playGame();  // Fonction principale pour jouer
int checkWinner();  // Vérifie si un joueur a gagné
void saveGame();  // Sauvegarde la partie
void loadGame();  // Charge une partie sauvegardée

#endif

