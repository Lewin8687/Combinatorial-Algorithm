// Dongyang Li, STUDENT ID: 7996582
#include <stdio.h>
#include <string.h>
#define bits 4

char last_result[500][bits];
char temp_result[500][bits];
int number=0;
int set[bits]={
	3,3,2,4
}; 

void Generate(int n);

int main(void)
{
	Generate(bits-1);
	int i,j;
	for(i=0;i<number;i++)
	{
		for(j=bits-1;j>=0;j--)
		{
			printf("%c",last_result[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void Generate(int n)
{
	int i,j,k;
	if(n==0)
	{
		for(i=0;i<set[n];i++)
		{
			number++;
			last_result[i][n]=(char)(((int)'0')+i);
		}
		return;
	}
	else
	{
		Generate(n-1);
		
		for(i=0;i<set[n];i++)
		{
			if(i%2==0)
			{
				for(j=0;j<number;j++)
				{
					for(k=0;k<n;k++)
					{
						temp_result[i*number+j][k]=last_result[j][k];
					}
					temp_result[i*number+j][n]=(char)(((int)'0')+i);
				}
			}
			else
			{
				for(j=0;j<number;j++)
				{
					for(k=0;k<n;k++)
					{
						temp_result[i*number+j][k]=last_result[number-j-1][k];
					}
					temp_result[i*number+j][n]=(char)(((int)'0')+i);
				}
			}
		}
	}
	number=number*set[n];
	
	for(i=0;i<number;i++)
	{
		for(j=0;j<n+1;j++)
		{
			last_result[i][j]=temp_result[i][j];
		}
	}
}
