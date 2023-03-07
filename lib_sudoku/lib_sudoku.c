#include <stdio.h>
#include <stdlib.h>
#include "../Biblio_C/biblio.h"
#include "lib_sudoku.h"

void afficher_grille(int **board)
{
    int i = 0;
    int j = 0;
    while(i < NBRE_LIGNE)
    {
        if(i % 3 == 0 && i != NBRE_LIGNE && i != 0)
        {
            mg_putstr("--------------------\n");
        }
        while(j < NBRE_COLONNE)
        {
            if((j + 1) % 3 == 0 && j != NBRE_COLONNE - 1)
            {
                mg_putchar('|');
            }
                mg_putchar(board[i][j] + '0');
                mg_putchar(' ');
            j++;
        }
        mg_putchar('\n');
        i++;
        j = 0;
    }
}
