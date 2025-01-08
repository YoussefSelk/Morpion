#ifndef GLOBALS_H
#define GLOBALS_H

extern char grid[3][3];       // Grille de jeu
extern int currentPlayer;     // Joueur courant (1 ou 2)
extern int gameMode;          // Mode de jeu: 1 pour Joueur vs IA, 2 pour Joueur vs Joueur
extern int gameModified;      // Flag pour savoir si le jeu a été modifié
extern int computerDifficulty;// Difficulté de l'ordinateur

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

