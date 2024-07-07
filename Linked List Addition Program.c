#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listnode {
	int data ;
	struct listnode *nextPtr ;
};
void insert(struct listnode** header,int data) ;
void replacement(struct listnode *header,int data) ;
void SumAdd(struct listnode* header,struct listnode *header1,struct listnode** answer,int i,int j) ;
void print(struct listnode* header) ;

int main () 
{
	char str1,str2 ;
	int i=0 ;
	int j =0 ;
	struct listnode *header = NULL ;
	struct listnode *header1 = NULL ;
	struct listnode *answer = NULL ;
	
	do{
		scanf("%c",&str1) ;
		if(str1 != '\n') 
		{
			if(i==0)
			{
				struct listnode *tmp =(struct listnode*) malloc(sizeof(struct listnode)) ;
				tmp -> data = str1-48 ;
				tmp -> nextPtr = NULL ;
				header = tmp ;
			}
			else
			{
				insert(&header, str1-48) ;
			}
		}
		i++ ;
	}while(str1 != '\n') ;
	
	do{
		scanf("%c",&str2) ;
		if(str2!='\n')
		{
			if(j==0)
			{
			struct listnode *tmp =(struct listnode*) malloc(sizeof(struct listnode)) ;
			tmp -> data = str2 - 48 ;
			tmp -> nextPtr = NULL ;
			header1 = tmp ;
			}
			else
			{
			insert(&header1,str2-48) ;
			}
		}
		j++ ;
	}while(str2!='\n') ;
	
	SumAdd(header,header1,&answer,i,j) ;
	print(answer) ;
	
	printf("\n") ;
	return 0 ;
}

void insert(struct listnode** header,int data) 
{
	struct listnode *newnode =(struct listnode*) malloc(sizeof(struct listnode)) ;
	newnode -> data = data ;
	newnode -> nextPtr = *header ;
	*header = newnode ;
}

void replacement(struct listnode *header,int data) 
{
	struct listnode *newnode =(struct listnode*) malloc(sizeof(struct listnode)) ;
	struct listnode *lastPtr = header ;
	
	newnode -> data = data ;
	newnode -> nextPtr = NULL ;
	
	if(header == NULL)
	{
		*header = *newnode ;
		return ;
	}
	while(lastPtr ->nextPtr != NULL)
	{
		lastPtr = lastPtr -> nextPtr ;
	}
	lastPtr -> nextPtr = newnode ;
	return ;
}

struct listnode* List(struct listnode* header, struct listnode* header1, int* rep)
{
	if(header == NULL)
	{
		return NULL ;
	}
	int sum ;
	struct listnode* result = (struct listnode*)malloc(sizeof(struct listnode)) ;
	sum = header->data + header1->data + *rep ;
	*rep = sum/10 ;
	sum = sum % 10 ;
	result -> data = sum ;
	result -> nextPtr = List(header->nextPtr,header1->nextPtr,rep) ;
	return result ;
}

void SumAdd(struct listnode* header,struct listnode *header1,struct listnode** answer,int i,int j)
{
	int rep = 0 ;
	
	if(header == NULL)
	{
		*answer = header1 ;
		return ;
	}
	else if (header1 == NULL)
	{
		*answer = header ;
		return ;
	}
	if(i==j)
	{
		*answer = List(header,header1,&rep) ;
	}
	else
	{
		int gap = abs(i-j) ;
		if(i<j)
		{
			for(i=0;i<gap;i++)
			{
				replacement(header,0) ;
			}
		}
		else if(i>j)
		{
			for(i=0;i<gap;i++)
			{
				replacement(header1,0) ;
			}
		}
		*answer = List(header,header1,&rep) ;
	}
	if(rep)
	{
		replacement(*answer,rep) ;
	}
}

void print(struct listnode* header)
{
	if(header == NULL)
	{
		return ;
	}
	print(header->nextPtr) ;
	printf("%d",header->data) ;
}
