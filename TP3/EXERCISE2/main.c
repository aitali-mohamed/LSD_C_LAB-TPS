nt main()
{
	//create() function pasted here to avoid using struct/array as the output of the function.
	int i;
	liste P=NULL;
	liste L=NULL;
	for(i=0;i<30;i++)
		ajoutDebut(rand() % 11, &P);
	for(i=0;i<10;i++)
		ajoutDebut(rand() % 11, &L);
	//End of the create() function that creates 2 lists full of random numbers between 1 and 10.
	
	//Showing the two randomly created lists.
	printf("\n");
	printf("The list P : \n");
	affichageListe(P);
	printf("\n");
	printf("The list L : \n");
	affichageListe(L);
	printf("\n");
	//end of showing.
	
	//Sorting the two lists and merging them.
	sortliste(&P);
	sortliste(&L);
	printf("The list P, sorted : \n");
	affichageListe(P);
	printf("\n");
	printf("The list L, sorted : \n");
	affichageListe(L);
	printf("\n");
	liste J=merge(L,P);
	printf("The list J, merged P and L : \n");
	affichageListe(J);
	printf("\n");
	//The end of showing and merging the two lists P and L into J.
	
	//Sorting the J list and removing duplicated numbers in the same list and printing it at the end.
	sortliste(&J);
	printf("\n");
	printf("The list J sorted but with duplicated numbers : \n");
	affichageListe(J);
	 printf("\n");
	removeDuplicate(&J);
	printf("The list J sorted without duplicated numbers : \n");
	affichageListe(J);
	
	//the end of removing duplicata and printing.
	
	//freeing the allocated memory...
	liberer(L);
	liberer(P);
	liberer(J);
	//the end of freeing...
	
	return 0;
}
