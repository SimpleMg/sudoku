#ifndef LIB_SUDOKU
#define LIB_SUDOKU
#define NBRE_LIGNE 9
#define NBRE_COLONNE 9
#define VRAI 1
#define FAUX 0

typedef int BOOL;

void afficher_grille(int **board);
BOOL horizontal_check(int **board);
BOOL vertical_check(int **board);
BOOL carre_check(int **board);
int** resolv_sudoku(int **board);


#endif
