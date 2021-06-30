int main(int ac, char **av) 
{
		liste L=NULL;
		L=convert(av);
		affichageListe(L);
		if (palyndrome(L)==0)
			printf("False\n");
		else
			printf("True\n");
		return 0;
} 

