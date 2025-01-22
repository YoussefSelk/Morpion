#ifndef GAME_H
#define GAME_H

extern int gameModified;
extern int currentPlayer;
extern int gameMode;
void initGame(int mode);  
void playGame(); 
int checkWinner();  
void exitGame();

#endif

