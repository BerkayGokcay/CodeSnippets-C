#include<stdio.h>

struct household
{
    int id;
    int income;
    int participants;
};
void average(struct household survey[],int count)
{
    int i;
    float avg,sum = 0 ;
    for(i=0;i<count;i++)
	{
        sum+=survey[i].income ;
    }
    avg= sum/count;
    printf("Average = %.0f \n",avg);
    for(i=0;i<count;i++)
    {
        if(survey[i].income>avg)
        {
            printf("Households above average value = %d %d\n",survey[i].id,survey[i].income);
        }
    }
}

void poverty_percent(struct household survey[],int count,float avg)
{

    int i ;
	float leveldown=0;
    float P;
    float result ;
    for(i=0;i<count;i++)
    {
    	P = 2000+(1000*(survey[i].participants - 2)) ;
        if((P>survey[i].income))
		{
            leveldown++;
        }
    }
    result = leveldown/count ;
    printf("Percent of the below the poverty level = %.2f\n",result) ;
}
int main()
{
    int count=0;
    float avg=0 ;
    struct household survey[25];
    printf("Enter -1 to exit the program. \n");
    while(1){
    	scanf("%d",&survey[count].id) ;
    	 if(survey[count].id==-1)
		{
            break;
        }
        scanf("%d %d",&survey[count].income,&survey[count].participants);
        count++;
    }
    average(survey,count) ;
    poverty_percent(survey,count,avg) ;
    return 0 ;
}

