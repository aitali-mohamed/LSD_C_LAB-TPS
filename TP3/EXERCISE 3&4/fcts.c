#include<header.h>

int is_empty(t_stack  * P)
{
    if(P==NULL)
        return 1;
    return 0;
}



void push(int x,t_stack  ** P)
{
    t_stack *  C=(t_stack *)malloc(sizeof(t_stack));
    C->data=x;
    C->next=*P;
    *P=C;
}



int pop(t_stack ** P)
{
int res  = 0;
    if(is_empty(*P)==0)
    {
        res=(*P)->data;
        t_stack * temp=*P;
        *P=(*P)->next;
        free(temp);
        return res;
    }
    else
        return INT_MIN;
}

t_stack * copie_inverse(t_stack *   p)
{
	t_stack * L = NULL;
	while(p!=NULL)
	{
		push((p)->data,&L);
			p=(p)->next;

	}
	return L;
}


void print_stack(t_stack *  P)
{
    if(P == NULL)
    {
	    printf("[]\n");
	    return;
    }	
    t_stack * temp=P;
    printf("[");
    while(temp->next!=NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    if(temp!=NULL)
        printf("%d]\n",temp->data);
}
int stack_len(t_stack * P)
{
	int s=0;
	t_stack * temp = P;
	while(temp!=NULL)
	{
		
		s++;
		temp=temp->next;
	}
	return s;




}

int RPN(char * ch)
{
	t_stack * p =NULL; 
	int i =0;
	while(ch[i])
	{

		if (isdigit(ch[i]))
		{
			char c = ch[i];
			
			int x=atoi(&c);
			//printf("%d\n",x);
			push(x,&p);
		}	
		i++;	
			
	}
	t_stack  * L = copie_inverse(p);
	//print_stack(L);
	i=2;
	int z = 0;
	while(ch[i])
	{
		
		if(ch[i]=='+')
		{
			int s = pop(&L);
			int r = pop(&L);
			push(s+r,&L);
			z++;
			
		}
		if(ch[i]=='-')
		{
			int s = pop(&L);
			int r = pop(&L);
			push(s-r,&L);
			z++;
		}
		if(ch[i]=='*')
		{
			int s = pop(&L);
			int r = pop(&L);
			push(s*r,&L);
			z++;
		}
		if(ch[i]=='/')
		{
			int s = pop(&L);
			int r = pop(&L);
			if (r==0)
			{
				printf("dividing by zero is undefined\n");
				exit(EXIT_FAILURE);
			}
			push(s/r,&L);
			z++;
		
		
		
		
		}
			if(ch[i]=='%')
		{
			int s = pop(&L);
			int r = pop(&L);
			if (r==0)
			{
				printf("dividing by zero is undefined\n");
				exit(EXIT_FAILURE);
			}
			push(s%r,&L);
			z++;
		
		
		
		
		}
		i++;
	
	}
	int m = z+1;
	if(m!=stack_len(p))
	{
		printf("error string isn't valid\n");
		exit(EXIT_FAILURE);
	}	
	
	//print_stack(L);
	//printf("%d test M \n",L->data);
	return pop(&L);
	
}


