#ifndef BIBLIO_H
#define BIBLIO_H

typedef struct My_List
{
    int data;
    struct My_List *next;
} List;


List *mg_initialisation_liste();
List* mg_ajouter_element(List *ma_liste, int element);
List *mg_freeList(List* my_list);
void mg_putList(List *ma_liste);
void mg_putchar(char c);
int mg_strlen(const char *str);
char* mg_strdup(char *str);
int mg_len_nombre(int nbr);
int puissance_10(int nbr);
int puissance(int nbr, int puissance);
int mg_len_tab(int *tab, int taille);
int mg_atoi(char *str);
char* mg_strjoin(char const *s1, char const *s2);
void mg_putstr(char *str);
char* mg_reverse_str(char *str);
void mg_putnbr(int nbr);
int *mg_tri_bulles(int* tab, int taille);
int mg_abs(int nbr);
int mg_isdigit(char nbr);
int *mg_tri_insertion(int *tab_int, int taille);
int mg_max_tab(int *tab, int taille);
int mg_min_tab(int *tab, int taille);
void mg_affiche_alphabet(void);
void mg_reverse_alphabet(void);
void mg_affiche_chiffre(void);
int mg_isneg(int nbr);
int mg_ispalindrome(char *str);

#endif
