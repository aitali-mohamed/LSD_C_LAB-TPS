#include<header.h>

void affichageListe(liste L)
{
    if(L==NULL)
        printf("[ ]");
   else
    {
        printf("[");
        liste temp=L;
        while(temp->suivant!=NULL)
        {
            printf("%c, ",temp->element);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("%c",temp->element);
        printf("]\n");
    }

}

void ajoutDebut(char x,liste * L)
{
    // Allocation de mémoire pour une nouvelle cellule
    liste C=(liste)malloc(sizeof(cellule));
    //Remplissage de la cellule	
    C->element=x;
    C->suivant= *L;
    // Ajout de la cellule au début de la liste
    *L= C;
}
// Exercice 1
liste convert(char **av)
{
	liste L=NULL;
	int j=0;
	while(av[1][j]!='\0')
		{
			ajoutDebut(av[1][j],&L);
			j++;
		}
	return L;
}

int palyndrome(liste L)
{
	liste P=NULL;
	liste temp1 = L;
	while(temp1->suivant!=NULL)
		{
			ajoutDebut(temp1->element, &P);
			temp1=temp1->suivant;
		}
	ajoutDebut(temp1->element, &P);
	temp1 = L;
	affichageListe(P);
	liste temp2 = P;
	while(temp1->suivant!=NULL)
		{
			if(temp1->element==temp2->element)
			{	
					temp1=temp1->suivant;
					temp2=temp2->suivant;
			}
			else
				return 0;
		}
	return 1;
}


