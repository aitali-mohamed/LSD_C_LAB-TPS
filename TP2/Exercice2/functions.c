#include "header.h"

int  **allocate_array(t_point t)
{
	int **d;
	int i;
	d=(int **)malloc(t.n*sizeof(int*));
	for (i=0 ;i<=t.n ;i++)
    	{
		d[i]=(int *)malloc(t.m*sizeof(int));
    	}
	return d;
}


int** array_inputs(int **d,t_point t)
{
	int i,j;
	for (i=0;i<t.n;i++)
    	{
		for (j=0;j<t.m;j++)
			{	
				printf("entrer t[%d][%d] ",i,j);
				scanf("%d",&d[i][j]);
			}
	}
}

void position(t_point t)
{
    printf("please enter positon:\n");
    scanf("n:%d \n m:%d",t.n ,t.m);
    
}
