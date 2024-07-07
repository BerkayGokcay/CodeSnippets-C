#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int corner ;
struct points{
	double x[100] ;
	double y[100] ;
};

typedef struct points Stack ;

double computeArea(Stack *pPtr,int corner) ;

int main()
{
	int i ;
	Stack *pPtr ;
	pPtr =(Stack*)malloc((corner+1)*sizeof(struct points)) ;
	double result ;
	printf("How many corner in the closed polygon : ") ; 
	scanf("%d",&corner) ;
	for(i=0;i<=corner;i++)
	{
		printf("Enter %d. corner's cordinates(x,y) : ",i+1) ;
		scanf("%lf%lf",&pPtr->x[i],&pPtr->y[i]) ;
	}
	result = computeArea(pPtr,corner) ;
	printf("Area : %.2lf\n",result) ;
	printf("!!! END !!!") ;
	return 0 ;
}

double computeArea(Stack *pPtr,int corner) 
{
	double area ;
	int i=0 ;
	for(i=0;i<corner;i++)
	{
		area +=(pPtr->x[i+1] + pPtr->x[i]) * (pPtr->y[i+1] - pPtr->y[i]) ;
	}
	area /= 2 ;
	return fabs(area) ;
}

