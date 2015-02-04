//Dongyang Li, STUDENT ID: 7996582
#include <stdio.h>
#include <math.h> 

int n=4;
int Num[4] = {1,2,2,3};
int output[4]={0};

int bit[4] = {0,0,0,0};
int result[100]={0};
int result_num=0; 
int used[4]={0};

void generate(int loop,int j);

int main(void)
{
    int remainder;
    int temp_result;
    int loop; 
   	int Max = (int)pow(2,n);
    int i,j;
    for(i=0;i<Max;i++)
    {
    	loop = 0;//useful bits number
    	temp_result=i;
    	for(j=n-1;j>-1;j--)//four bits 
    	{
	    	remainder=temp_result%2;//1 means can use 
	    	temp_result=(temp_result-remainder)/2;
	    	bit[j]=remainder;
	    	used[j]=1-remainder;
	    	loop+=remainder;
	    }
		generate(loop-1,0);
    }
    for(i=0;i<result_num;i++)
    {
    	printf("Number:%d\n",i+1);
    	printf("%d\n",result[i]);
    }
    return 0;
}

void generate(int loop,int j)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			output[j]=Num[i];
			if(loop == j)
			{
				int k;
				int temp;
				double pw;
				for(k=0;k<loop+1;k++)
				{
					pw=pow(10,loop-k);
					temp = (int)pw * output[k];
					result[result_num]+=temp;
				}
				bool _flag=false;
				for(k=0;k<result_num;k++)
				{
					if(result[result_num]==result[k])
					{
						_flag=true;
						break;
					}
				}
				if(_flag==true)
				{
					result[result_num]=0;
				}
				else
				{
					result_num++;
				}
			}
			else
			{
				generate(loop,j+1);
			}
			used[i]=0;
		}
	}
}
