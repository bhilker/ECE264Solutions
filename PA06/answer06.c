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

int isDecreasing(int budget,int *partition,int len)
{
	int test=TRUE;
	int i=1;
	while(i<len)
	{
		if(partition[i]>=partition[i-1]) test=FALSE;
		i++;
	}

	//if(partition[i-1]==budget) test=FALSE;

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
	if(budget==0) printPartition(partition,pos);

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
	if(budget==0) printPartition(partition,pos);

	//Recursive Case
	int spending=0;
	for(spending=1;spending<=budget;spending++)
	{

		if(isIncreasing(budget,partition,pos) && budget-sumPartition(partition,pos)>=0)
		{
			partition[pos]=spending;
			partitionIncreasingHelper(budget-spending,partition,pos+1);
		}
	}

}

void partitionDecreasingHelper(int budget,int *partition,int pos)
{
	//Base Case
	if(budget==0) printPartition(partition,pos);

	//Recursive Case
	int spending=0;
	for(spending=1;spending<=budget;spending++)
	{
		if(pos==0)
		{
			partition[pos]=spending;
			partitionDecreasingHelper(budget-spending,partition,pos+1);			
		}
		else if(isDecreasing(budget,partition,pos) && sumPartition(partition,pos)>=budget+1)
		{
			partition[pos]=spending;
			partitionDecreasingHelper(budget-spending,partition,pos+1);
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

}

void partitionEven(int value)
{

}

void partitionOddAndEven(int value)
{

}

void partitionPrime(int value)
{

}

