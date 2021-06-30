int main()
{
	list L=NULL;
	add_node(3,&L);
	add_node(0,&L);
	add_node(88,&L);
	print_list(L);
	list N = L->next;
	remove_node(N);
	print_list(L);
	return 0;
}	


