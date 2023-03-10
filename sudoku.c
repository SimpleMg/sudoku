#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "Biblio_C/biblio.h"
#include "lib_sudoku/lib_sudoku.h"

int main(int argc, char **argv)
{
    /*VERIFIE SI L'UTILISATEUR PASSE BIEN LE FICHIER TEXT EN ARGUMENT*/
    if (argc < 2)
    {
        mg_putstr("Merci de renseigner le fichier txt exemple: ./a.out exemple.txt\n");
        return 0;
    }
    /*RECUPERATION DES DONNEES DU FICHIER TXT*/
    char buffer[200];
    int fd = open(argv[1], O_RDONLY);
    read(fd, buffer, 200);
    close(fd);
    /*CREATION DE LA GRILLE*/
    // Allocation de la mémoire
    int **board = (int **)malloc(NBRE_LIGNE * sizeof(int *));
    if (board == NULL)
    {
        mg_putstr("Mauvaise allocation mémoire\n");
        return 0;
    }
    int i, j, i_buffer;
    i = 0;
    while (i < NBRE_LIGNE)
    {
        board[i] = (int *)malloc(NBRE_LIGNE * sizeof(int));
        if (board[i] == NULL)
        {
            mg_putstr("Mauvaise allocation mémoire\n");
            return 0;
        }
        i++;
    }
    // remplissage de la grille
    i = 0;
    j = 0;
    i_buffer = 0;
    while (i < NBRE_LIGNE)
    {
        while (j < NBRE_COLONNE)
        {
            if (buffer[i_buffer] >= '0' && buffer[i_buffer] <= '9')
            {
                board[i][j] = buffer[i_buffer] - '0';
                j++;
            }
            i_buffer++;
        }
        i++;
        j = 0;
    }
    // affiche de la grille
    resolve_sudoku(board, 0);
    afficher_grille(board);
    
    return 1;
}


