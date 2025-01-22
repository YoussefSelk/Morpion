#include "globals.h"

char grid[3][3];       // Initialisation de la grille
int currentPlayer = 1; // Le premier joueur commence
int gameMode = 0;      // Mode non défini par défaut
int gameModified = 0;  // Le jeu n'est pas modifié au début
int computerDifficulty = 1; // Difficulté de l'ordinateur initialisée à 'Easy'

int ingame = 0;
int game_finished = 0;
int loading = 0;

char player1Symbol = 'X';
char player2Symbol = 'O';

// Initialisation des couleurs pour l'affichage du jeu
char* player1Color = NULL;
char* player2Color = NULL;
// Bleu pour le joueur 2
char* gridColor = "\033[0m";        // Couleur par défaut (reset)
