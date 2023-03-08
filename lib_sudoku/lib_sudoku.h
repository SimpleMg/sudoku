#ifndef LIB_SUDOKU
#define LIB_SUDOKU
#define NBRE_LIGNE 9
#define NBRE_COLONNE 9
#define TRUE 1
#define FALSE 0

typedef int BOOL;

void afficher_grille(int **board);
BOOL verif_ligne(int **board, int ligne, int valeur);
BOOL verif_colonne(int **board, int colonne, int valeur);
BOOL verif_3x3(int **board, int ligne, int colonne, int valeur);
BOOL valide(int **board, int i,int j,int valeur);




#endif
