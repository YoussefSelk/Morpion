#ifndef PLAYER_H
#define PLAYER_H

void playerMove(int player);  // Tour du joueur
void computerMove();  // Tour de l'ordinateur (en fonction de la difficulté)

void setDifficulty(int difficulty);  // Définit la difficulté
void getRandomEmptyCell(int *row, int *col);
int canWinOrBlock(char player);
#endif

