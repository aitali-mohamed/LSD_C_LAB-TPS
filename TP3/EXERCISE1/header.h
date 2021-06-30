#ifndef HEADER
#define HEADER


#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct cellule
{
    char element;
    struct cellule * suivant;
 
};
typedef struct cellule cellule;
typedef struct cellule * liste;



void affichageListe(liste)
void ajoutDebut(char,liste)
liste convert(char **)
int palyndrome(liste)


#endif
