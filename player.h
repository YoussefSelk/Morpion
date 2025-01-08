#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int gamesWon;
    int gamesLost;
    int gamesDrawn;
} PlayerStats;

extern PlayerStats player1Stats;
extern PlayerStats player2Stats;

void playerMove(int player);
void computerMove();
void setDifficulty(int difficulty);
void getRandomEmptyCell(int *row, int *col);
int canWinOrBlock(char player);

void updateStats(int winner); 
void displayStats(); 
void saveStats(); // Fonction pour sauvegarder les statistiques
void loadStats(); // Fonction pour charger les statistiques

#endif

