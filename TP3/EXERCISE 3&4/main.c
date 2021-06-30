int main(int ac , char ** av)
{
	if (ac!=2)
		return printf("we need 2 arg\n");	
	int n =RPN(av[1]);
	printf("%d\n",n);
	return 0;
		
}

