#include "answer06.h"
#include <stdlib.h>
#include <stdio.h>

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
}

void partitionAll(int value);
{
	int *partition=malloc(sizeof(int)*value);
	partitionAllHelper(value,partition,0);
	free(partition);	
}

void partitionIncreasing(int value)
{

}

void partitionDecreasing(int value)
{

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

