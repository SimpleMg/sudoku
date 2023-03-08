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
            mg_putstr("-------------------------\n");
        }
        while(j < NBRE_COLONNE)
        {
            if(j  % 3 == 0) //cette ligne c pour traiter le dernier cas de l'affichage 
            {
                mg_putstr("| ");
            }
                mg_putchar(board[i][j] + '0');
                mg_putchar(' ');
            j++;
        }
        mg_putstr("|\n");
        i++;
        j = 0;
    }
}






/*
BOOL horizontal_check(int **board)
{

}

BOOL vertical_check(int **board)
{

}

BOOL carre_check(int **board)
{

}

int **resolv_sudoku(int **board)
{
    return board;
}*/
