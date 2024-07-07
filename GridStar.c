#include <stdio.h>
#include <stdlib.h>
void current_position(int *pos1,int pos2,int pos3,int pos4,int pos5) ;
int main()
{
	int number,blob,p1,p2 ;
	int i,j ;
	int grid[3][11] ;
	FILE *fPtr ;
	if ((fPtr = fopen("input.txt","r")) == NULL)
	{
	printf("Error! File could not be opened.");
	return 0 ;
	}
	else
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<11;j++)
			{
				grid[i][j]=0 ;
			}
			
		}
		fscanf(fPtr,"%d",&number) ;
		blob = 0 ;
		for(i=0;i<number;i++)
		{
			fscanf(fPtr,"%d",&p1) ;
			fscanf(fPtr,"%d",&p2) ;
			grid[p1][p2]=1 ;
		}
		for(i=0;i<3;i++)
		{
			for(j=0;j<11;j++)
			{
				if(grid[i][j]== 1)
				{
					printf("* ") ;
				}
				else
				{
					printf("  ") ;
				}
			}
			printf("\n") ;
		}
		for(i=0;i<3;i++)
		{
			for(j=0;j<11;j++)
			{
				if(grid[i][j]== 1)
				{
					current_position((int *)grid,i,j,3,11);
					blob = blob + 1 ;
				}
			}
		}
	}
	printf("\n%d",blob) ;
	fclose(fPtr);
	return 0 ;
}
void current_position(int *pos1,int pos2,int pos3,int pos4,int pos5)
{
	if(pos2<0 || pos2>=3 || pos3 <0  || pos3>=11 || *((pos1+pos2*pos5)+pos3)!=1)
	{
		return ;
	}
*((pos1+pos2*pos5)+pos3) = 2 ;
current_position(pos1,pos2+1,pos3,pos4,pos5) ;
current_position(pos1,pos2,pos3+1,pos4,pos5) ;
current_position(pos1,pos2-1,pos3,pos4,pos5) ;
current_position(pos1,pos2,pos3-1,pos4,pos5) ;
}
	

