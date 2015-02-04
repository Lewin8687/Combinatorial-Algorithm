// Dongyang Li , student ID:7996582
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> 

#define N 8
#define D 4

int number = 1;

struct node 
{
	int x[N];
	struct node *p;
};	

struct node *head = (struct node*)malloc(sizeof(struct node));

void Nonlinear(int current,int n)
{
	if(n>number)
	{
		number = n;
	}
	if(current>=pow(2,N))
	{
		return;
	}

	int i,x[N],a=current;
	
	// dec to bit
	for(i=N-1;i>=0;i--)
	{
		x[i]=a%2;
		a=a/2;
	}
	
	struct node *temp=head;
	int repeat = 0;
	while(temp)
	{
		for(i=0;i<N;i++)
		{
			if(temp->x[i]==x[i])
			{
				repeat++;
			}
		}
		if(repeat>(N-D))
		{
			//FAIL
			break;
		}
		if(temp->p)
		{
			temp=temp->p;
			repeat = 0;
		}
		else
		{
			repeat = 0;
			break;
		}
	}
	if(repeat>0)
	{
		//fail
		Nonlinear(current+1,n);
	}
	else
	{
		//it is acceptable
		// case 2 : add
		struct node *new_node =(struct node*)malloc(sizeof(struct node));
		for(i=0;i<N;i++)
		{
			new_node->x[i]=x[i];
		}
		new_node->p=NULL;
		temp->p=new_node;
		Nonlinear(current+1,n+1);
		struct node *temp1;
		
		temp1=temp->p;
		temp->p=NULL;
		struct node *temp2;
		while(temp1->p)
		{
			temp2=temp1->p;
			free(temp1);
			temp1=temp2;
		}
		free(temp1);
		
		// case 1 : abandon
		while(temp->p)
		{
			temp=temp->p;
		}
		Nonlinear(current+1,n);
	}
}

int main()
{
	head->p=NULL;
	memset(head->x,0,sizeof(int)*N);
	clock_t start_time = clock();
	Nonlinear(0,1);
	clock_t end_time = clock();
	printf("n:%d\n",N);
	printf("number:%d\n",number);
	printf("duration:%d\n",end_time-start_time);
	return 0;
}
