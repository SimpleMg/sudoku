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
        if(i % 3 == 0)
        {
            mg_putstr("-------------------------\n");
        }
        while(j < NBRE_COLONNE)
        {
            if(j % 3 == 0) //cette ligne c pour traiter le dernier cas de l'affichage 
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
    mg_putstr("-------------------------\n");
}


BOOL verif_ligne(int **board, int ligne, int valeur)
{
    int i;
    i = 0;
    while(i < NBRE_COLONNE)
    {
        if(board[ligne][i] == valeur)
        {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}


BOOL verif_colonne(int **board, int colonne, int valeur)
{
    int i;
    i = 0;
    while(i < NBRE_COLONNE)
    {
        if(board[i][colonne] == valeur)
        {
            return FALSE;
        }
        i++;
    }
    return TRUE;
}

BOOL verif_3x3(int **board, int ligne, int colonne, int valeur)
{
    int i = 0, j = 0;
    int k = ligne - (ligne % 3);
    int l = colonne - (colonne % 3);
    while(i < k + 3)
    {
        while(j < l + 3)
        {
            if(board[i][j] == valeur)
            {
                return FALSE;
            }
            j++;
        }
        i++;
    }
    return TRUE;
}


BOOL valide(int **board,int ligne, int colonne, int valeur)
{
    if(!verif_ligne(board, ligne, valeur))
    {
        return FALSE;
    }
    if(!verif_colonne(board, colonne, valeur))
    {
        return FALSE;
    }
    if(!verif_3x3(board, ligne, colonne, valeur))
    {
        return FALSE;
    }
    return TRUE;
}

BOOL resoudre_sudoku(int **board, int position)
{
    if (position == NBRE_COLONNE * NBRE_LIGNE)
    {
        return TRUE;
    }
    int ligne = position / NBRE_LIGNE;
    int colonne = position % NBRE_COLONNE;
    if (board[ligne][colonne] != 0)
    {
        return resoudre_sudoku(board, position + 1);
    }
    for (int i = 1; i <= 9; i++)
    {
        if (valide(board, ligne, colonne, i))
        {
            board[ligne][colonne] = i;
            if (resoudre_sudoku(board, position + 1))
            {
                return TRUE;
            }
        }
    }
    board[ligne][colonne] = 0;
    return FALSE;
}

