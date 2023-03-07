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
    if(argc != 3)
    {
        mg_putstr("Merci de renseigner le fichier txt exemple: ./a.out 3 exemple.txt\n");
        return 0;
    }
    /*RECUPERATION DES DONNEES DU FICHIER TXT*/
    char buffer[1024];
    int fd = open(argv[2], O_RDONLY);
    int size = read(fd, buffer, 1024);
    close(fd);
    /*CREATION DE LA GRILLE*/
    //Allocation de la mémoire
    int **board = (int**)malloc(NBRE_LIGNE * sizeof(int*));
    if(board == NULL)
    {
        mg_putstr("Mauvaise allocation mémoire\n");
        return 0;
    }
    int i, j, i_buffer;
    i = 0;
    while(i < NBRE_LIGNE)
    {
        board[i] = (int*)malloc(NBRE_LIGNE * sizeof(int));
        if(board[i] == NULL)
        {   
            mg_putstr("Mauvaise allocation mémoire\n");
            return 0;
        }
        i++;
    }
    //remplissage de la grille
    i = 0;
    j = 0;
    i_buffer = 0;
    while(i < NBRE_LIGNE)
    {
        while(j <= NBRE_COLONNE)
        {
            if(buffer[i_buffer] >= '0' && buffer[i_buffer] <= '9')
            {
                board[i][j] = buffer[i_buffer] - '0';
            }
            j++;
            i_buffer++;
        }
        i++;
        j = 0;
    }
    //affiche de la grille
    afficher_grille(board);
    /*RESOLUTION DE LA GRILLE*/
    board = resolv_sudoku(board);
    afficher_grille(board);
    return 1;
}
