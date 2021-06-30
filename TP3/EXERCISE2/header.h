#ifndef HEADER
#define HEADER


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct cellule
{
    int num;
    struct cellule * suivant;
};

typedef struct cellule cellule;
typedef struct cellule * liste;
#endif
