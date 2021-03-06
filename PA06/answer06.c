#include "answer06.h"
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int sumPartition(int *partition, int len)
{
	int i;
	int sum=0;
	for(i=0;i<len;i++)
		sum+=partition[i];
	return sum;
}
//This function tests if the partition is increasing
int isIncreasing(int budget,int *partition,int len)
{
	int test=TRUE;
	int i=1;
	while(i<len)
	{
		if(partition[i]<=partition[i-1]) test=FALSE;
		i++;
	}

	if(partition[i-1]==budget) test=FALSE;

	return test;
}

int isEven(int budget, int *partition,int len)
{
	int test=TRUE;
	int i=0;
	while(i<len)
	{
		if(partition[i]%2==1) test=FALSE;

		i++;
	}

	return test;
}

int isPrime(int number)
{
	int i;

	for(i=2;i<number;i++)
	{
		if(number % i==0) return FALSE;
	}
	if(number==1) return FALSE;
	return TRUE;
}

int isDecreasing(int budget,int *partition,int len)
{
	int test=TRUE;
	int i=1;
	while(i<len)
	{
		if(partition[i]>=partition[i-1]) test=FALSE;
		i++;
	}

	if(partition[i-1] < budget) test=FALSE;

	return test;
}


void printPartition(int *partition, int length)
{
	int i;
	printf("= ");
	for(i=0;i<length;i++)
	{
		if(i!=0) printf(" + ");
		printf("%d",partition[i]);
	}
	printf("\n");
}

void partitionAllHelper(int budget,int *partition,int pos)
{
	//Base Case
	if(budget==0) 
	{	
		printPartition(partition,pos);
		return;
	}
	//Recursive Case
	int spending=0;
	for(spending=1;spending<=budget;spending++)
	{
		partition[pos]=spending;
		partitionAllHelper(budget-spending,partition,pos+1);
	}
}

void partitionIncreasingHelper(int budget,int *partition, int pos)
{
	//Base Case
	if(budget==0)
	{	
		printPartition(partition,pos);
		return;
	}
	//Recursive Case
	int spending=0;
	int start=pos == 0 ? 1:partition[pos-1]+1;
	for(spending=start;spending<=budget;spending++)
	{

		//if(isIncreasing(budget,partition,pos) && budget-sumPartition(partition,pos)>=0)
		//{
			partition[pos]=spending;
			partitionIncreasingHelper(budget-spending,partition,pos+1);
		//}
	}

}

void partitionDecreasingHelper(int budget,int *partition,int pos)
{
	//Base Case
	if(budget==0)
	{	
		printPartition(partition,pos);
		return;
	}
	//Recursive Case
	int spending=0;
	int start=pos==0 ? budget:partition[pos-1]-1;
	for(spending=start;spending>0;spending--)
	{
		//if(pos==0)
		//{
		//	partition[pos]=spending;
		//	partitionDecreasingHelper(budget-spending,partition,pos+1);			
		//}
		//else if(isDecreasing(budget,partition,pos) && spending != partition[pos-1])
		//{
			partition[pos]=spending;
			partitionDecreasingHelper(budget-spending,partition,pos+1);
		//}
	}
}

void partitionOddHelper(int budget,int *partition,int pos)
{
	//Base Case
	if(budget==0)
	{
		printPartition(partition,pos);
		return;
	}	
	//Recursive Case
	int spending;
	for(spending=1;spending<=budget;spending+=2)
	{
		//printf("\nSpending:%d\n",spending);
			partition[pos]=spending;
			partitionOddHelper(budget-spending,partition,pos+1);		
	}
}

void partitionEvenHelper(int budget,int *partition,int pos)
{
	//Base Case
	if(budget==0)
	{
		printPartition(partition,pos);
		return;
	}	
	//Recursive Case
	int spending;
	for(spending=2;spending<=budget;spending +=2)
	{
			partition[pos]=spending;
			partitionEvenHelper(budget-spending,partition,pos+1);	
	}
}

void partitionPrimeHelper(int budget,int *partition,int pos)
{
	//Base Case
	if(budget==0)
	{
		printPartition(partition,pos);
		return;
	}	
	//Recursive Case
	int spending;
	for(spending=2;spending<=budget;spending++)
	{
		if(!isPrime(spending)) continue;
		partition[pos]=spending;
		partitionPrimeHelper(budget-spending,partition,pos+1);
	}
}

void partitionOddAndEvenHelper(int budget,int *partition,int pos)
{
	//Base Case
	if(budget==0)
	{
		printPartition(partition,pos);
		return;
	}	
	//Recursive Case
	int spending;
	for(spending=1;spending<=budget;spending++)
	{
		if(pos==0)
		{
			partition[pos]=spending;
			partitionOddAndEvenHelper(budget-spending,partition,pos+1);
		}
		else if((partition[pos-1]%2==0 && spending%2==1)||(partition[pos-1]%2==1 && spending%2==0))
		{
			partition[pos]=spending;
			partitionOddAndEvenHelper(budget-spending,partition,pos+1);
		}
	}
}

void partitionAll(int value)
{
	int *partition=malloc(sizeof(int)*value);
	partitionAllHelper(value,partition,0);
	free(partition);	
}

void partitionIncreasing(int value)
{
	int *partition=malloc(sizeof(int)*value);
	partitionIncreasingHelper(value,partition,0);
	free(partition);
}

void partitionDecreasing(int value)
{
	int *partition=malloc(sizeof(int)*value);
	partitionDecreasingHelper(value,partition,0);
	free(partition);
}

void partitionOdd(int value)
{
	int *partition=malloc(sizeof(int)*value);
	int i=0;
	while(i<value)
	{
		partition[i]=0;
		i++;
	}
	partitionOddHelper(value,partition,0);
	free(partition);
}

void partitionEven(int value)
{	
	int *partition=malloc(sizeof(int)*value);
	int i=0;
	while(i<value)
	{
		partition[i]=0;
		i++;
	}
	partitionEvenHelper(value,partition,0);
	free(partition);
}

void partitionOddAndEven(int value)
{
	int *partition=malloc(sizeof(int)*value);
	partitionOddAndEvenHelper(value,partition,0);
	free(partition);
}

void partitionPrime(int value)
{
	int *partition=malloc(sizeof(int)*value);
	partitionPrimeHelper(value,partition,0);
	free(partition);
}

