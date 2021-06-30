#include<header.h>



int testVide(liste L)
{
    if(L==NULL)
        return 1;
    return 0;
}
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
            printf("%d, ",temp->num);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("%d",temp->num);
        printf("]\n");
    }

}

void ajoutDebut(int x,liste * L)
{
    // Allocation de m�moire pour une nouvelle cellule
    liste C=(liste)malloc(sizeof(cellule));
    //Remplissage de la cellule	
    C->num=x;
    C->suivant= *L;
    // Ajout de la cellule au d�but de la liste
    *L= C;
}

// Longueur d'une liste.
unsigned longueur(liste L)
{
    unsigned l=0;
    if(testVide(L)==0)
    {
        liste temp=L;
        while(temp!=NULL)
        {
            l+=1;
            temp=temp->suivant;
        }
    }
    return l;
}

void liberer(liste L)
{
	liste temp=L;
	free(temp);
	return;
}

 
void create()
{
	int i;
	liste P=NULL;
	liste L=NULL;
	for(i=0;i<100;i++)
		ajoutDebutNum(rand() % 11, &P);
	for(i=0;i<30;i++)
		ajoutDebutNum(rand() % 11, &L);
	return P,L;
}

void suppressionDebut(liste * L)
{
    if(L!=NULL)
    {
        liste temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
    return;
}

// Suppresion de la fin d'une liste.
void suppressionFin(liste * L)
{
    if(L==NULL)
    {
        return;
    }
    if((*L)->suivant==NULL)
    {
        free(*L);
        *L=NULL;
    }
    else
    {
        // Acces à la dernière et à la l'avant dernière cellules
        liste temp=*L;
        liste temp_1=*L;
        while(temp->suivant!=NULL)
        {
            temp_1=temp;
            temp=temp->suivant;
        }
        temp_1->suivant=NULL;
        free(temp);
    }
    return;
}

void sortliste(liste * L)
{
	liste temp3=* L;
	int z=0;
	while(temp3!=NULL)
	{
			liste temp1=* L;
			liste temp2=(*L)->suivant;
		while(temp2!=NULL)
		{
				if(temp1->num>temp2->num)
				{
					z=temp2->num;
					temp2->num=temp1->num;
					temp1->num=z;	
				}
		temp1=temp1->suivant;
		temp2=temp2->suivant;	
		}
	temp3=temp3->suivant;
	}
	return;
}

liste merge(liste L, liste P)
{
	liste J=NULL;
	liste temp1 = L;
	liste temp2 = P;
	while(temp1!=NULL)
	{
		ajoutDebut(temp1->num, &J);
		temp1=temp1->suivant;
	}
	while(temp2!=NULL)
	{
		ajoutDebut(temp2->num, &J);
		temp2=temp2->suivant;
	}
	return J;
}

void supprimer(liste * L, int i)
{
	liste temp = * L;
	liste temp1=NULL;
	int j=0;
	if(i>=longueur(*L))
		return;
	if(i==0)
		suppressionDebut(L);
	if(i==longueur(*L)-1)
		suppressionFin(L);
	else
	{
		while(j<i-1)
		 {
		 	temp=temp->suivant;
		 	j=j+1;
		 }
	temp1=temp->suivant;
	temp->suivant=temp1->suivant;;
	free(temp1);
	}
	return;
}

void removeDuplicate(liste * L)
{
	liste  temp1= *L;
	int z=temp1->num;
	int i=1;
	temp1=temp1->suivant;
	while(temp1!=NULL)
	{
		if(temp1->num==z)
		{
			temp1=temp1->suivant;
			supprimer(L,i);
		}
		else
			{
				z=temp1->num;
				temp1=temp1->suivant;
				i=i+1;	
			}
	}
	return;          
}

