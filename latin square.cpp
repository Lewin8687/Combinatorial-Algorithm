// Dongyang Li , student ID:7996582
#include <stdio.h>
#include <string.h>
#include <malloc.h> 
#include <time.h> 

#define n 2

int count = 0;
int num = 0;
void Latinsquare(int l, int (*CurM)[n])//l starts from 0
{
	num++;
	int dirty[n]={0};
	int i;
	if(l==((n-1)*(n-1)-1))
	{
		for(i=0;i<n-2;i++)
		{
			dirty[CurM[n-2][i]-1]=1;	
		}
		for(i=0;i<n-1;i++)
		{
			if(dirty[i]==0)
			{
				CurM[n-2][n-2]=i+1;
			}
		}
		int j;
		count++;
		free(CurM);
	}
	else
	{
		int row = l/(n-1);
		int column = l-row*(n-1);
		
		dirty[column+1]=1;
		dirty[row+1]=1;
		//same row
		for(i=0;i<column;i++)
		{
			dirty[CurM[row][i]-1]=1;
		} 
		//same column
		for(i=0;i<row;i++)
		{
			dirty[CurM[i][column]-1]=1;
		} 
		for(i=0;i<n;i++)
		{
			if(dirty[i]==0)
			{
				CurM[row][column]=i+1;
				int (*CurM1)[n] = (int ((*)[n]))malloc(sizeof(int)*n*n);
				memcpy(CurM1,CurM,sizeof(int)*n*n);
				Latinsquare(l+1,CurM1);
				free(CurM1);
			}
		}	
	}
}

int main()
{
	clock_t dwStart = clock();
	int (*CurM)[n] = (int ((*)[n]))malloc(sizeof(int)*n*n);
	Latinsquare(0, CurM);
	clock_t dwEnd = clock();
	free(CurM);
	printf("n:%d\n",n);
	printf("duration(ms):%d\n",(dwEnd-dwStart));
	printf("number of results:%d\n",count);
	printf("number of nodes visited:%d\n",num);
	return 0;
}
