#ifndef GLOBALS_H
#define GLOBALS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
	#include <windows.h>  // For Windows API
#else
	#include <unistd.h>   // For sleep/usleep on Unix
#endif
extern char grid[3][3];       // Grille de jeu
extern int currentPlayer;     // Joueur courant (1 ou 2)
extern int gameMode;          // Mode de jeu: 1 pour Joueur vs IA, 2 pour Joueur vs Joueur
extern int gameModified;      // Flag pour savoir si le jeu a été modifié
extern int computerDifficulty;// Difficulté de l'ordinateur
extern int ingame;  // 1 if in a game, 0 otherwise
extern int game_finished;
extern int loading;
// Définition des symboles par défaut pour les joueurs
extern char player1Symbol;
extern char player2Symbol;

// Définition des couleurs pour l'affichage du jeu
extern char* player1Color;
extern char* player2Color;
extern char* gridColor;



// Définitions des couleurs pour l'interface
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define LINE "\033[1;34m" 
#define NUM "\033[1;32m"
#define CYAN "\033[36m"
#define LINE "\033[1;34m" // Blue color for lines

#endif

