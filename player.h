#ifndef PLAYER_H
#define PLAYER_H

void playerMove(int player);  // Tour du joueur
void computerMove();  // Tour de l'ordinateur (en fonction de la difficult�)

void setDifficulty(int difficulty);  // D�finit la difficult�
void getRandomEmptyCell(int *row, int *col);
int canWinOrBlock(char player);
#endif

