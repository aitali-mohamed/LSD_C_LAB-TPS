#ifndef HEADER
#define HEADER


#include<stdio.h>
#include<stdlib.h>

struct t_list
{
	int data;
	struct t_list * next;


};
typedef struct t_list t_list;
typedef t_list * list;



// Prototypes

list create_node(int); 
void add_node(int  , list*);
list arraytoliste(int* , int );  
void print_liste(list ); 
void remove_node( list*);  
void free_node(t_list L);

#endif
