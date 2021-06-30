
#include<header.h>





// create a node
list create_node(int x)
{
	list new_node = (list)malloc(sizeof(t_list));
	new_node->data = x;
	return new_node;
	
}



/// add a node to the end of the list
void add_node(int x ,list * L)
{
	list P=create_node(x);
	P->next=NULL;
	if(*L == NULL)
		*L=P;
	else
	{
		list temp = *L;
		while(temp->next != NULL)
			temp=temp->next;
		temp->next = P;
		return;	
	}	
}

/// convert array to list
list array_to_list(int * T,int n)
{
	list L = NULL;
	for(int i=0;i<n;i++)
		add_node(T[i],&L);
	return L;	
}




/// print elements of a list
void print_list(list L)
{
if(L==NULL)
        printf("[ ]");
    else
    {
        printf("[");
        list temp=L;
        while(temp->next!=NULL)
        {
            printf("%d, ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        printf("]\n");
    }

}





/// remove a node from list
void remove_node(list N)
{
/*	if(N==NULL)
		return;
	if(N->next==NULL)
		printf("this is last node,require head,can't be freed");
		return;*/
	list temp = N->next;
	list g=N->next;
	N->data = g->data;
	printf("%d\n",N->next->data);
	N->next = g->next;
	free(temp);
	return;
}




















